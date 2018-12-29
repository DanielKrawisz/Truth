#ifndef TRUTH_LOGIC_INTUINISTIC_HPP
#define TRUTH_LOGIC_INTUINISTIC_HPP

#include <truth/logic/contradiction.hpp>
#include <truth/logic/implies.hpp>
#include <truth/statement/operation.hpp>
#include <truth/constant.hpp>
#include <truth/operate.hpp>

namespace truth {
    
    namespace logic {
        
        namespace intuitionistic {
            
            template <typename x, typename y> struct And;
            
            template <typename x, typename y> struct Or;
            
            template <typename x, typename y> struct Implies;
            
            template <typename x> 
            using Not = Implies<x, contradiction>;
            
            namespace axiom {
                template <typename x, typename y>
                using Then1 = Implies<x, Implies<x, y>&>;
                
                template <typename x, typename y, typename z>
                using Then2 = Implies<Implies<x, Implies<y, z>&>&, Implies<Implies<x, y>&, Implies<x, z>&>&>;
                
                template <typename x, typename y>
                using And1 = Implies<And<x, y>, x>;
                
                template <typename x, typename y>
                using And2 = Implies<And<x, y>, y>;
                
                template <typename x, typename y>
                using And3 = Implies<x, Implies<y, And<x, y>>&>;
                
                template <typename x, typename y>
                using Or1 = Implies<x, Or<x, y>&>;
                
                template <typename x, typename y>
                using Or2 = Implies<y, Or<x, y>&>;
                
                template <typename x, typename y, typename z>
                using Or3 = Implies<Implies<x, z>&, Implies<Implies<y, z>&, Implies<Or<x, y>&, z>&>&>;
                
                template <typename X> 
                using False = Implies<contradiction, X>;
            }
            
            template <typename x, typename y> struct And {
                x Left;
                y Right;
            };
            
            template <typename x, typename y> struct Or {
                virtual x left() const = 0;
                virtual y right() const = 0;
                virtual bool is_left() const = 0;
            };
        
            template <typename x, typename y> 
            struct Implies<x, Implies<y, x>&> {
                
                struct constant : public Implies<y, x>, public truth::constant<y>{};
                
                Implies<y, x>& operator()(x a) const {
                    return *new constant{a};
                }
            };
        
            template <typename x, typename y, typename z> 
            struct Implies<Implies<x, Implies<y, z>&>&, Implies<Implies<x, y>&, Implies<x, z>&>&> {
                
                struct operation : public Implies<x, z>, public truth::operate<Implies<x, Implies<y, z>&>&, Implies<x, y>&> {};
                
                struct application : public Implies<Implies<x, y>&, Implies<x, z>&> {
                    Implies<x, Implies<y, z>&>& Function;
                    
                    Implies<x, z>& operator()(Implies<x, y>& exp) const {
                        return *new operation{Function, exp};
                    }
                };
                
                Implies<Implies<x, y>&, Implies<x, z>&>& operator()(Implies<x, Implies<y, z>&>& exp) const {
                    return *new application{exp};
                }
            };
        
            template <typename x, typename y> 
            struct Implies<And<x, y>&, x> {                
                x operator()(And<x, y> a) const {
                    return a.Left;
                }
            };
            
            template <typename x, typename y> 
            struct Implies<And<x, y>&, y> {                
                y operator()(And<x, y> a) const {
                    return a.Right;
                }
            };
            
            template <typename x, typename y> 
            struct Implies<x, Implies<y, And<x, y>>&> {
                struct incomplete_and : public Implies<y, And<x, y>> {
                    x Left;
                    
                    And<x, y> operator()(y b) {
                        return And<x, y>{Left, b};
                    }
                };
                
                Implies<y, And<x, y>>& operator()(x a) const {
                    return *new incomplete_and{a};
                }
            };
            
            class illogical : std::exception {
                string What;
                        
            public:
                illogical(string w) : What{w} {}
                
                const char* what() const noexcept final override {
                    return What.c_str();
                }
            };
        
            template <typename x, typename y> struct left_or : public Or<x, y> {
                x Left;
                virtual x left() const final override {
                    return Left;
                }
                
                virtual y right() const final override {
                    throw illogical("wrong side");
                }
                
                bool is_left() const final override (
                    return true;
                );
            };
        
            template <typename x, typename y> struct right_or : public Or<x, y> {
                y Right;
                virtual x left() const final override {
                    throw illogical("wrong side");
                }
                
                virtual y right() const final override {
                    return Right;
                }
                
                bool is_left() const final override (
                    return true;
                );
            };
            
            template <typename x, typename y> 
            struct Implies<x, Or<x, y>&> {                
                Or<x, y>& operator()(x a) const {
                    return left_or<x, y>{a};
                }
            };
            
            template <typename x, typename y> 
            struct Implies<y, Or<x, y>&> {                
                Or<x, y>& operator()(y b) const {
                    return right_or<x, y>{b};
                }
            };
            
            template <typename x>
            struct Implies<contradiction, x> {
                x operator()(contradiction c) {
                    return illogical("contradictory");
                }
            };
        }
    }
    
    namespace statement {
        template <typename x, typename y>
        struct writer<logic::intuitionistic::Implies<x, y>> {
            static string write() {
                return statement::write<operation<operand::Implies, x, y>>();
            }
        };
        
        template <typename x, typename y>
        struct writer<logic::intuitionistic::And<x, y>> {
            static string write() {
                return statement::write<operation<operand::And, x, y>>();
            }
        };
        
        template <typename x, typename y>
        struct writer<logic::intuitionistic::Or<x, y>> {
            static string write() {
                return statement::write<operation<operand::Or, x, y>>();
            }
        };
    }
}

#endif

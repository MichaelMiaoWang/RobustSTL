#ifndef STACK_H
#define STACK_H

#include "list.h"


namespace RobustSTL {

template <typename Object>
class stack : public RobustSTL::list<Object>
{
public:
    stack()
    {
        
    }
    
     size_t size( ) const
       { return lis.size( ); }

     bool isEmpty( ) const
       { return size( ) == 0; }

     void clear( )
     {
         while( !lis.isEmpty( ) )
             lis.pop_back( );
     }

     Object & top( )
       { return *(--lis.end( )); }

     const Object & top( ) const
       { return *(--lis.end( )); }

     void push( const Object & x )
       { lis.push_back( x ); }


     void pop( )
       {
           if(lis.size > 0)
               lis.pop_back( );
       }
    
private:
    RobustSTL::list<Object> lis;
    
    
};  /* end of class stack */

}   /* end of namespace RobustSTL */


#endif /* STACK_H */

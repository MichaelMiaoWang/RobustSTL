#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

namespace RobustSTL {

template <typename Object>
class queue : public RobustSTL::list<Object>
{
public:
    queue()
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

     Object & front( )
       { return *(lis.begin( )); }

     const Object & front( ) const
       { return *(lis.begin( )); }

     void push( const Object & x )
       { lis.push_back( x ); }


     void pop( )
       {
           if(lis.size() > 0)
               lis.pop_front( );
       }
    
private:
    RobustSTL::list<Object> lis;
}; /* end of class queue */

} /* end of namespace RobustSTL */

#endif /* QUEUE_H */

#ifndef DEQUE_H
#define DEQUE_H

#include "list.h"

namespace RobustSTL {

template <typename Object>
class deque : public RobustSTL::list<Object>
{
public:
    deque()
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
      { return *( lis.begin( ) ); }
    Object & back( )
      { return *(--lis.end( ) ); }
    
    const Object & front( ) const
      { return *( lis.begin( ) ); }
    
    const Object & back( ) const
      { return *( --lis.end( ) ); }
    
    void push_back ( const Object & x )
       { lis.push_back( x ); }
    
     void push_front ( const Object & x )
       { lis.push_front( x ); }

     void pop_front( )
       {
           if( lis.size() > 0 )
               lis.pop_front( );
       }
     void pop_back( )
      {
         if( lis.size() > 0 )
             lis.pop_back( );
      }
private:
    RobustSTL::list<Object> lis;
    
}; /* end of class deque */

} /* end of namespace RobustSTL */

#endif /* DEQUE_H */

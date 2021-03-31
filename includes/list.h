#ifndef LIST_H
#define LIST_H

#include <algorithm>
using namespace std;


namespace RobustSTL {

template <typename Object>
class list
{
  private:
    //双向链表的定义
    struct Node
    {
        Object  data;
        Node   *prev;
        Node   *next;

        Node( const Object & d = Object{ }, Node * p = nullptr, Node * n = nullptr )
          : data{ d }, prev{ p }, next{ n } { }
        
        Node( Object && d, Node * p = nullptr, Node * n = nullptr )
          : data{ std::move( d ) }, prev{ p }, next{ n } { }
    };

  public:
    class const_iterator
    {
      public:
  
        const_iterator( ) : current{ nullptr }
          { }
        
        //返回迭代器所指向的元素
        const Object & operator* ( ) const
          { return retrieve( ); }
        
        const_iterator & operator++ ( )
        {
            current = current->next;
            return *this;
        }
        
        //后置++运算符
        const_iterator operator++ ( int )
        {
            const_iterator old = *this;
            ++( *this );
            return old;
        }

        const_iterator & operator-- ( )
        {
            current = current->prev;
            return *this;
        }
        
        //后置--运算符
        const_iterator operator-- ( int )
        {
            const_iterator old = *this;
            --( *this );
            return old;
        }
            
        bool operator== ( const const_iterator & rhs ) const
          { return current == rhs.current; }

        bool operator!= ( const const_iterator & rhs ) const
          { return !( *this == rhs ); }

      protected:
        Node *current;

       
        Object & retrieve( ) const
          { return current->data; }

        const_iterator( Node *p ) :  current{ p }
          { }
        
        friend class list<Object>;
    };

    class iterator : public const_iterator
    {
      public:


        iterator( )
          { }

        Object & operator* ( )
          { return const_iterator::retrieve( ); }

        const Object & operator* ( ) const
          { return const_iterator::operator*( ); }
        
        iterator & operator++ ( )
        {
            this->current = this->current->next;
            return *this;
        }

        iterator operator++ ( int )
        {
            iterator old = *this;
            ++( *this );
            return old;
        }

        iterator & operator-- ( )
        {
            this->current = this->current->prev;
            return *this;
        }

        iterator operator-- ( int )
        {
            iterator old = *this;
            --( *this );
            return old;
        }

      protected:
        iterator( Node *p ) : const_iterator{ p }
          { }

        friend class list<Object>;
    };

  public:
    list( )
      { init( ); }

    ~list( )
    {
        clear( );
        delete head;
        delete tail;
    }

    list( const list & rhs )
    {
        init( );
        for( auto & x : rhs )
            push_back( x );
    }

    list & operator= ( const list & rhs )
    {
        list copy = rhs;
        std::swap( *this, copy );
        return *this;
    }

    
    list( list && rhs )
      : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
   
    list & operator= ( list && rhs )
    {
        std::swap( theSize, rhs.theSize );
        std::swap( head, rhs.head );
        std::swap( tail, rhs.tail );
        
        return *this;
    }
    
    iterator begin( )
      { return iterator( head->next ); }

    const_iterator begin( ) const
      { return const_iterator( head->next ); }

    iterator end( )
      { return iterator( tail ); }

    const_iterator end( ) const
      { return const_iterator( tail ); }

    size_t size( ) const
      { return theSize; }

    bool isEmpty( ) const
      { return size( ) == 0; }

    void clear( )
    {
        while( !isEmpty( ) )
            pop_front( );
    }

    Object & front( )
      { return *begin( ); }

    const Object & front( ) const
      { return *begin( ); }

    Object & back( )
      { return *--end( ); }

    const Object & back( ) const
      { return *--end( ); }

    void push_front( const Object & x )
      { insert( begin( ), x ); }

    void push_back( const Object & x )
      { insert( end( ), x ); }

    void push_front( Object && x )
      { insert( begin( ), std::move( x ) ); }

    void push_back( Object && x )
      { insert( end( ), std::move( x ) ); }

    void pop_front( )
      { erase( begin( ) ); }

    void pop_back( )
      { erase( --end( ) ); }

    // 在itr迭代器指向的元素之前插入x，传入的x为左值版本
    iterator insert( iterator itr, const Object & x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ x, p->prev, p } );
    }

    // 在itr迭代器指向的元素之前插入x，传入的x为右值的版本
    iterator insert( iterator itr, Object && x )
    {
        Node *p = itr.current;
        ++theSize;
        return iterator( p->prev = p->prev->next = new Node{ std::move( x ), p->prev, p } );
    }
    
    // 删除itr迭代器所指向的元素
    iterator erase( iterator itr )
    {
        Node *p = itr.current;
        iterator retVal( p->next );
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --theSize;

        return retVal;
    }
    
    // 删除从from到to的元素
    iterator erase( iterator from, iterator to )
    {
        for( iterator itr = from; itr != to; )
            itr = erase( itr );

        return to;
    }

  private:
    size_t   theSize;
    Node *head;
    Node *tail;

    void init( )
    {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};      /* end of class list */

} /* end of namespace RobustSTL */

#endif

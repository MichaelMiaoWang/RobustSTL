#ifndef VECTOR_H
#define VECTOR_H

#include "dsexceptions.h"
#include <algorithm>
#include <iostream>
namespace RobustSTL {

template <typename Object>
class vector
{
  public:
    
    //各种构造函数
    
    //使用explicit关键字防止编译器进行隐式转换
    explicit vector( size_t initSize = 0 )
      : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      {
          objects = new Object[ theCapacity ];
      }
    
    // initSize:向量大小， initValue:元素的初始值
    vector( size_t initSize, Object initValue )
      : theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
      {
          objects = new Object[ theCapacity ];
          for( size_t i = 0; i < initSize; ++i )
          {
              objects[ i ] = initValue;
          }
      }
    
    vector( const vector & rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
    {
        objects = new Object[ theCapacity ];
        for( size_t k = 0; k < theSize; ++k )
            objects[ k ] = rhs.objects[ k ];
    }
    
    vector( vector && rhs )
      : theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }
   
    //使用等号初始化向量，等号右边为左值版本
    vector & operator= ( const vector & rhs )
    {
        vector copy = rhs;
        std::swap( *this, copy );
        return *this;
    }
    
    
   //使用等号初始化向量，等号右边为右值版本
    vector & operator= ( vector && rhs )
    {
        std::swap( theSize, rhs.theSize );
        std::swap( theCapacity, rhs.theCapacity );
        std::swap( objects, rhs.objects );
        
        return *this;
    }
    
    //析构函数
    ~vector( )
      { delete [ ] objects; }


    
    
    bool isEmpty( ) const
      { return size( ) == 0; }
    size_t size( ) const
      { return theSize; }
    size_t capacity( ) const
      { return theCapacity; }

    Object & operator[]( size_t index )
    {
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
        return objects[ index ];
    }

    const Object & operator[]( size_t index ) const
    {
        if( index < 0 || index >= size( ) )
            throw ArrayIndexOutOfBoundsException{ };
        return objects[ index ];
    }

    void resize( size_t newSize )
    {
        if( newSize > theCapacity )
            reserve( newSize * 2 );
        theSize = newSize;
    }

    void reserve( size_t newCapacity )
    {
        if( newCapacity < theSize )
            return;

        Object *newArray = new Object[ newCapacity ];
        for( size_t k = 0; k < theSize; ++k )
            newArray[ k ] = std::move( objects[ k ] );

        theCapacity = newCapacity;
        std::swap( objects, newArray );
        delete [ ] newArray;
    }

      //插入左值到向量中
    void push_back( const Object & x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = x;
    }
      //插入右值到向量中
    void push_back( Object && x )
    {
        if( theSize == theCapacity )
            reserve( 2 * theCapacity + 1 );
        objects[ theSize++ ] = std::move( x );
    }
        //将向量末尾元素删除，实际上并未删除，只是将末尾元素的索引-1。
    void pop_back( )
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        --theSize;
    }
        //返回末尾元素的索引
    const Object & back ( ) const
    {
        if( isEmpty( ) )
            throw UnderflowException{ };
        return objects[ theSize - 1 ];
    }

      // 迭代器，实际上就是元素的指针
    typedef Object * iterator;
    typedef const Object * const_iterator;

    iterator begin( )
      { return &objects[ 0 ]; }
    const_iterator begin( ) const
      { return &objects[ 0 ]; }
    iterator end( )
      { return &objects[ size( ) ]; }
    const_iterator end( ) const
      { return &objects[ size( ) ]; }

    static const size_t SPARE_CAPACITY = 2;

  private:
    size_t theSize;    //目前的向量元素数量
    size_t theCapacity;    //向量目前最大的容量，可以进行扩容。
    Object * objects;   //向量元素数组指针
    
}; /* end of class vector */



} /* end of namespace RobustSTL */




#endif /* VECTOR_H */


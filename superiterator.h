#ifndef SUPERITERATOR_H
#define SUPERITERATOR_H

#include <string>
#include <iostream>
#include <exception>
#include <memory>

using std::overflow_error;
using std::underflow_error;
using std::string;

template<typename typeObj, template<typename, typename> class typeCollection, typename _Alloc = std::allocator<typeObj> >
class IteratorSuperPower
{
    typedef double(typeObj::*FPtr)();
public:
    IteratorSuperPower(typeCollection<typeObj, _Alloc> collection, FPtr ptr, string operation, double value) :
        m_collection(collection),
        m_ptr(ptr),
        m_operation(operation),
        m_value(value)
    {
        this->m_iterator = this->m_collection.begin();
        this->m_riterator = this->m_collection.rbegin();
    }




    bool hasNext()
    {
        typename typeCollection<typeObj, _Alloc>::iterator currentPosition = this->m_iterator;

        while(this->m_iterator != this->m_collection.end())
        {
            if(!this->m_operation.compare("<"))
            {
                if( ((*this->m_iterator).*this->m_ptr)() < this->m_value )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare(">"))
            {
                if( ((*this->m_iterator).*this->m_ptr)() > this->m_value )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }




            if(!this->m_operation.compare(">="))
            {
                if( ((*this->m_iterator).*this->m_ptr)() >= this->m_value )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }




            if(!this->m_operation.compare("<="))
            {
                if( ((*this->m_iterator).*this->m_ptr)() <= this->m_value )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }




            if(!this->m_operation.compare("=="))
            {
                if( ((*this->m_iterator).*this->m_ptr)() == this->m_value )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }




            if(!this->m_operation.compare("!="))
            {
                if( ((*this->m_iterator).*this->m_ptr)() != this->m_value )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare(" ") || this->m_operation.empty() )
            {
                if( this->m_iterator != this->m_collection.end() )
                {
                    this->m_iterator = currentPosition;
                    return true;
                }
            }

            ++this->m_iterator;

        }

        this->m_iterator = currentPosition;
        return false;
    }




    bool hasPrevious()
    {
        typename typeCollection<typeObj, _Alloc>::reverse_iterator currentPosition = this->m_riterator;

        while(this->m_riterator != this->m_collection.rend())
        {

            if(!this->m_operation.compare("<"))
            {
                if( ((*this->m_riterator).*this->m_ptr)() < this->m_value )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare(">"))
            {
                if( ((*this->m_riterator).*this->m_ptr)() > this->m_value )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare(">="))
            {
                if( ((*this->m_riterator).*this->m_ptr)() >= this->m_value )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare("<="))
            {
                if( ((*this->m_riterator).*this->m_ptr)() <= this->m_value )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare("=="))
            {
                if( ((*this->m_riterator).*this->m_ptr)() == this->m_value )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare("!="))
            {
                if( ((*this->m_riterator).*this->m_ptr)() != this->m_value )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            if(!this->m_operation.compare(" ") || this->m_operation.empty() )
            {
                if( this->m_riterator != this->m_collection.rend() )
                {
                    this->m_riterator = currentPosition;
                    return true;
                }
            }

            ++this->m_riterator;

        }

        this->m_riterator = currentPosition;
        return false;
    }




    typeObj &next()
    {
        while(true)
        {
            if(!this->m_operation.compare("<"))
            {
                if( (*(this->m_iterator).*this->m_ptr)() < this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;

                    if(this->m_iterator == this->m_collection.end()) throw std::overflow_error("Overflow!");

                    ++this->m_iterator;

                    return *current;
                }

                ++this->m_iterator;
                continue;
            }


            if(!this->m_operation.compare(">"))
            {
                if( (*(this->m_iterator).*this->m_ptr)() > this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;

                    if(this->m_iterator == this->m_collection.end()) throw std::overflow_error("Overflow!");

                    ++this->m_iterator;
                    return *current;
                }

                ++this->m_iterator;
                continue;
            }

            if(!this->m_operation.compare(">="))
            {
                if( (*(this->m_iterator).*this->m_ptr)() >= this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;

                    if(this->m_iterator == this->m_collection.end()) throw std::overflow_error("Overflow!");

                    ++this->m_iterator;
                    return *current;
                }

                ++this->m_iterator;
                continue;
            }

            if(!this->m_operation.compare("<="))
            {
                if( (*(this->m_iterator).*this->m_ptr)() <= this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;

                    if(this->m_iterator == this->m_collection.end()) throw std::overflow_error("Overflow!");

                    ++this->m_iterator;
                    return *current;
                }

                ++this->m_iterator;
                continue;
            }

            if(!this->m_operation.compare("=="))
            {
                if( (*(this->m_iterator).*this->m_ptr)() == this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;

                    if(this->m_iterator == this->m_collection.end()) throw std::overflow_error("Overflow!");

                    ++this->m_iterator;
                    return *current;
                }

                ++this->m_iterator;
                continue;
            }

            if(!this->m_operation.compare("!="))
            {
                if( (*(this->m_iterator).*this->m_ptr)() != this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;

                    if(this->m_iterator == this->m_collection.end()) throw std::overflow_error("Overflow!");

                    ++this->m_iterator;
                    return *current;
                }

                ++this->m_iterator;
                continue;
            }

            if(!this->m_operation.compare(" ") || this->m_operation.empty() )
            {
                typename typeCollection<typeObj, _Alloc>::iterator current = this->m_iterator;
                ++this->m_iterator;
                return *current;
            }
        }
    }


    typeObj &previous()
    {
        while(true)
        {

            if(!this->m_operation.compare("<"))
            {
                if( (*(this->m_riterator).*this->m_ptr)() < this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::reverse_iterator current = this->m_riterator;

                    if(this->m_riterator == this->m_collection.rend()) throw std::underflow_error("Underflow!");

                    ++this->m_riterator;
                    return *current;
                }

                ++this->m_riterator;
                continue;
            }

            if(!this->m_operation.compare(">"))
            {
                if( (*(this->m_riterator).*this->m_ptr)() > this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::reverse_iterator current = this->m_riterator;

                    if(this->m_riterator == this->m_collection.rend()) throw std::underflow_error("Underflow!");

                    ++this->m_riterator;
                    return *current;
                }

                ++this->m_riterator;
                continue;
            }

            if(!this->m_operation.compare("<="))
            {
                if( (*(this->m_riterator).*this->m_ptr)() <= this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::reverse_iterator current = this->m_riterator;

                    if(this->m_riterator == this->m_collection.rend()) throw std::underflow_error("Underflow!");

                    this->m_riterator++;
                    return *current;
                }

                ++this->m_riterator;
                continue;
            }

            if(!this->m_operation.compare(">="))
            {
                if( (*(this->m_riterator).*this->m_ptr)() >= this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::reverse_iterator current = this->m_riterator;

                    if(this->m_riterator == this->m_collection.rend()) throw std::underflow_error("Underflow!");

                    ++this->m_riterator;
                    return *current;
                }

                ++this->m_riterator;
                continue;
            }

            if(!this->m_operation.compare("=="))
            {
                if( (*(this->m_riterator).*this->m_ptr)() == this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::reverse_iterator current = this->m_riterator;

                    if(this->m_riterator == this->m_collection.rend()) throw std::underflow_error("Underflow!");

                    ++this->m_riterator;
                    return *current;
                }

                ++this->m_riterator;
                continue;
            }

            if(!this->m_operation.compare("!="))
            {
                if( (*(this->m_riterator).*this->m_ptr)() != this->m_value )
                {
                    typename typeCollection<typeObj, _Alloc>::reverse_iterator current = this->m_riterator;

                    if(this->m_riterator == this->m_collection.rend()) throw std::underflow_error("Underflow!");

                    ++this->m_riterator;
                    return *current;
                }

                ++this->m_riterator;
                continue;
            }
        }
    }

    inline typeObj &current()
    {
        return *this->m_iterator;
    }

    inline typeObj &reverse_current()
    {
        return *this->m_riterator;
    }

private:
    double m_value;
    string m_operation;
    FPtr m_ptr;
    typeCollection<typeObj, _Alloc> m_collection;
    typename typeCollection<typeObj, _Alloc>::iterator m_iterator;
    typename typeCollection<typeObj, _Alloc>::reverse_iterator m_riterator;
};

#endif // SUPERITERATOR_H

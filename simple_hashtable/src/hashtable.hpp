#pragma once

#include <functional>
#include <vector>
#include <iostream>

/////////// Element ///////////////////

template<typename Key, typename Value>
struct Element
{
    Element(const Key& key, const Value& value);
    Key  m_key;
    Value m_value;
    Element* m_next = 0;
};

template<typename Key, typename Value>
Element<Key, Value>::Element(const Key& key, const Value& value) :
    m_key(key),
    m_value(value),
    m_next(0)
{

}


/////////// HashTable ///////////////////

template<typename Key, typename Value>
class HashTable
{
    public:
        HashTable() = delete;
        HashTable(size_t size, const std::function<int(const Key&)>& m_hashingFunction);

        void add(const Key& key, const Value& value);

        void remove(const Key& key);

        void set(const Key& key, const Value& newValue);

        const Value& get(const Key& key) const;

        void print() const;
        
    private:
        std::function<int(const Key&)> m_hasher;

        std::vector<Element<Key, Value>* > m_values;
};




/////////// HashTable implementation ///////////////////

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t size, const std::function<int(const Key&)>& m_hashingFunction) :
    m_hasher(m_hashingFunction)
{
    // TODO dynamically-sized hash table

    m_values.resize(size);

    for ( auto& value : m_values )
        value = 0;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::add(const Key& key, const Value& value)
{
    size_t index = m_hasher(key);

    if (m_values.at(index) == 0)
    {
        m_values.at(index) = new Element<Key, Value>(key, value);
    }
    else
    {
        Element<Key, Value>* newElement = new Element<Key, Value>(key, value);

        Element<Key, Value>* iterator = m_values.at(index);

        while ( iterator->m_next != 0 )
        {
            iterator = iterator->m_next;
        }

        iterator->m_next = newElement;
    }
}

template<typename Key, typename Value>
static void DeleteNode(Element<Key, Value>*& ptrNode)
{
    Element<Key, Value>* nodeToBeDeleted = ptrNode;

    ptrNode = ptrNode->m_next;

    delete nodeToBeDeleted;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::remove(const Key& key)
{
    size_t index = m_hasher(key);

    if (m_values.at(index) == 0)
    {
        return;
    }

    if (m_values.at(index)->m_key == key)
    {
        DeleteNode(m_values.at(index));
        return;
    }

    for (Element<Key, Value>* it = m_values.at(index); it != 0 and it->m_next != 0; it = it->m_next)
    {
        if (it->m_next->m_key == key)
        {
            DeleteNode(it->m_next);
            return;
        }
    }
}

template<typename Key, typename Value>
void HashTable<Key, Value>::set(const Key& key, const Value& newValue)
{
    size_t index = m_hasher(key);

    for (Element<Key, Value>* it = m_values.at(index); it != 0; it = it->m_next)
    {
        if (it->m_key == key)
        {
            it->m_value = newValue;
            return;
        }
    }

    std::cout << "Sorry, could not find element with key: " << key << std::endl;
}

template<typename Key, typename Value>
const Value& HashTable<Key, Value>::get(const Key& key) const
{
    size_t index = m_hasher(key);

    for (Element<Key, Value>* it = m_values.at(index); it != 0; it = it->m_next)
    {
        if (it->m_key == key)
            return it->m_value;
    }

    throw ("Sorry, could not find element with key: " + key);
}

template<typename Key, typename Value>
void HashTable<Key, Value>::print() const
{
    if (m_values.size() == 0)
    {
        std::cout << "table: <empty>" << std::endl;
    }
    else
    {
        std::cout << "table: " << std::endl;
    }

    for ( size_t i = 0; i < m_values.size(); i++)
    {
        std::cout << "[ " << i << " ] = ";

        for (Element<Key, Value>* it = m_values.at(i); it != 0; it = it->m_next)
        {
            std::cout << "\033[37m" << it->m_value << "\033[0m "
                      << "(key:\033[1m" << it->m_key << "\033[0m"
                      << " next:\033[1m" << it->m_next << "\033[0m"
                      << ") ---> ";
        }

        std::cout << "\033[31m//\033[0m" << std::endl;
    }
}

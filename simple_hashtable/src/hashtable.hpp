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

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t size, const std::function<int(const Key&)>& m_hashingFunction) :
    m_hasher(m_hashingFunction)
{
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
            std::cout << it->m_value << " ---> ";
        }
    }
}
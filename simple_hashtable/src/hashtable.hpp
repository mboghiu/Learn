#pragma once

#include <functional>
#include <vector>
#include <iostream>

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

        std::vector<Value> m_values;

        const std::string m_santinel;
};

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t size, const std::function<int(const Key&)>& m_hashingFunction) :
    m_hasher(m_hashingFunction),
    m_santinel("***")
{
    m_values.resize(size);

    for ( auto& value : m_values )
        value = m_santinel;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::add(const Key& key, const Value& value)
{
    size_t index = m_hasher(key);

    if (m_values.at(index) != m_santinel)
        std::cout << "\033[1;31m CRASH >> collision at index: " << index << "\033[0m" << std::endl;

    m_values.at(index) = value;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::print() const
{
    if (m_values.size() == 0)
        std::cout << "table: <empty>" << std::endl;
    else
        std::cout << "table: " << std::endl;

    for ( size_t i = 0; i < m_values.size(); i++)
        std::cout << "[ " << i << " ] = " << m_values.at(i) << std::endl;
}

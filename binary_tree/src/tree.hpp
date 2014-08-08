#pragma once

#include <string>
#include <sstream>

#include "node.hpp"

template<typename T>
class bt
{
    public:
        void Insert(const T& value);
        void Delete(const T& value); 
        bool Search(const T& value) const;
        
        std::string DFTraverse_preorder() const;
        std::string DFTraverse_inorder() const;
        std::string DFTraverse_postorder() const;

        std::string BFTraverse() const;

    private:
        Node<T>* _tree = nullptr;



};

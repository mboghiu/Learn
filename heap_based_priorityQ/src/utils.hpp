#pragma once

#include <iostream>
#include <map>
#include <queue>

#include "priority_queue.hpp"

enum class options { UNKNOWN, MK, LS, HEAPIFY, PEEK, DELETE_ROOT, UPDATE_KEY, INSERT, Q};

namespace utils
{
    void print(size_t index, const std::string& contents);
    void print(const std::map<size_t , PriorityQueue>& queues);

    options str2enum(const std::string& command);

    void read_input(std::istream& stream, std::string& command, std::vector<size_t>& arguments);
}

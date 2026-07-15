#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string component;
        
        // Split the path by '/'
        while (std::getline(ss, component, '/')) {
            // Skip empty tokens (caused by '//') or current directory tokens ('.')
            if (component == "" || component == ".") {
                continue;
            }
            // Move up a directory if '..' is encountered
            if (component == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                // It's a valid directory name, push it to our stack
                stack.push_back(component);
            }
        }
        
        // Build the simplified canonical path
        std::string result = "";
        for (const std::string& dir : stack) {
            result += "/" + dir;
        }
        
        // If the stack was empty, return "/" (root directory)
        return result.empty() ? "/" : result;
    }
};
#pragma once

#include <functional>

struct Point {
	int x, y;
	
	bool operator==(const Point& a) const
	{
		return (x == a.x && y == a.y);
	}
};

// Hashing for Point so it can be used in std::unordered_map / std::unordered_set
namespace std {
    template <>
    struct hash<Point> {
        std::size_t operator()(const Point& p) const {
            return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
        }
    };
}

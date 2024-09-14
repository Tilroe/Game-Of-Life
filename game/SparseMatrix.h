
#include "Kernel.h"
#include <unordered_set>
#include "point.h"

class SparseMatrix :
    public Kernel
{
public:
    SparseMatrix(const int width, const int height);
    void update() override;
    void draw(const int TILE_SIZE) const override;
    void toggle(const int x, const int y) override;

private:
    void swap() override;
    std::vector<std::unordered_set<Point>> buffers;
    std::unordered_set<Point>* current_;
    std::unordered_set<Point>* next_;
};

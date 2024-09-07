
#include "game.h"
class SparseMatrixGame :
    public Game
{
public:
    void update(float dt) override;
    void draw() const override;

private:
    void swap() override;
};

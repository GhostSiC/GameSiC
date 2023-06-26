#include <MainEngine.hpp>
#include <memory>

int main()
{
    std::unique_ptr<MainEngine> mainEngine = std::make_unique<MainEngine>();
    mainEngine->initEngine();

    return 0;
}
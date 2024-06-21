#include <MainEngine.hpp>
#include <memory>

// new = heap,   stos to arg w f()   | lepiej na heap duze obj

int main()
{
    std::unique_ptr<MainEngine> mainEngine = std::make_unique<MainEngine>();
    mainEngine->mainLoop();

    return 0;
}
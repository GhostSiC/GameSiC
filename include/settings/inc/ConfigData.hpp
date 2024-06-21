#include <string>

namespace Config
{
    struct WindowData
    {
        ~WindowData() = default;
        std::string language;
        float resolutionWidth;
        float resolutionHeight;
    };

    struct AudioData
    {
        ~AudioData() = default;
        int volume;
    };

    struct GameSettingsData
    {
        ~GameSettingsData() = default;
        int difficult;
        int character; // for start only 2 no mod
    };
}
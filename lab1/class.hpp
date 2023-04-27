#include <SFML/Graphics.hpp>
#include <unistd.h>

class MyText
{
    private:
        std::string m_text; // классовая строка
        double m_time;     // классовая задержка
    public:
        MyText() {}

        MyText(const std::string& text, const double& time) 
        {
            m_text = text;
            m_time = time;
        }

        void AnimationText()
        {
            int WindowX = 2500; int WindowY = 400;
            sf::RenderWindow window(sf::VideoMode(WindowX, WindowY), "Sagitov lab");

            std::string croppWord;
            bool flag = true;

            double duration;   // промежуток между выводом символов
            duration = m_time * 1000000 / (m_text.size() - 1);

            sf::Text word;  // текст
            sf::Font font;  // шрифт
            font.loadFromFile("font.ttf");
            word.setFont(font);
            word.setCharacterSize(300);
            word.setFillColor(sf::Color::Black);
            word.setPosition(0, 0);

            while (window.isOpen())
            {
                sf::Event event;
                while ((window.pollEvent(event)))
                {
                    if (event.type == sf::Event::Closed) 
                        window.close();
                }

                if (flag)
                {
                    for (int i = 0; i < m_text.length() + 1; i++)
                    {   
                        croppWord = m_text.substr(0, i);
                        usleep(duration);

                        word.setString(croppWord);
                        window.clear(sf::Color::White);
                        window.draw(word);
                        window.display(); 

                        if (i == m_text.length())
                        {
                            flag = false;
                        }
                    }
                }
            }
        }
        ~MyText() {}
};

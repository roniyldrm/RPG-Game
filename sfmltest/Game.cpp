#include "Game.hpp"

void Game::initVars() {
    this->window = nullptr;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow() {

    std::ifstream ifs("Config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "None";
    sf::VideoMode Window_bounds{sf::VideoMode::getDesktopMode()};

    unsigned framerate_limit = 120;
    bool vsync_enabled = false;
    unsigned int antialiasing_level = 0;

    if (ifs.is_open()) {
        std::getline(ifs, title);
        ifs >> Window_bounds.size.x >> Window_bounds.size.y;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vsync_enabled;
        ifs >> antialiasing_level;
    }
    ifs.close();

    this->window_settings.antiAliasingLevel = antialiasing_level;
    if (this->fullscreen) 
        this->window = new sf::RenderWindow(Window_bounds, title, sf::State::Fullscreen, this->window_settings);
    else 
        this->window = new sf::RenderWindow(Window_bounds, title, sf::State::Windowed, this->window_settings);
    

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vsync_enabled);
}

void Game::initKeys() {

    std::ifstream ifs("Config/supported_keys.ini");
    
    if (ifs.is_open()) {
        std::string key = "";
        int key_value{};

        while (ifs >> key >> key_value) {
            this->supportedKeys[std::move(key)] = sf::Keyboard::Key(key_value);
        }
    }
    ifs.close();
}

void Game::initStates() {
    this->states.push(new MainMenuState(this->window, &(this->supportedKeys), this->states));
    //this->states.push(new GameState(this->window, &(this->supportedKeys)) );
}
Game::Game() {
    this->initVars();
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game() {
    delete this->window;
    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Game::endApplication() {

    //std::println("ending application");
}

void Game::updateDt() {
    this->dt = this->dtClock.restart().asSeconds();
    system("cls");
   // std::println("{} delta time", this->dt);
}


void Game::update() {
    this->updateSFMLevents();

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit()) {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    
    }
    //application ends
    else {
        this->endApplication();
        this->window->close();
    }
}

void Game::updateSFMLevents() {
    // Process events
    while (this->sfEvent = this->window->pollEvent()) {
        // Close window: exit
        if (this->sfEvent->is<sf::Event::Closed>())
            this->window->close();
    }
}

void Game::render() {
    this->window->clear();

    //render items

    if (!this->states.empty()) {
        this->states.top()->render();
    }

    this->window->display();
}

void Game::run() {

    while (window->isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

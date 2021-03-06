#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "Character.hpp"

class Zombie : public Character {
    using sf::Drawable::draw;

    public:
        enum ZombieState {
            Idle = 0,
            Walk,
            Chase
        };

        enum Direction {
            Down = 0,
            Left,
            Right,
            Up
        };

        Zombie(Party* p, sf::Texture* tex, sf::Image* collisionMap, int nS, int nF);

        void update(float deltaTime);
        void draw(sf::RenderWindow* window);


        int getPoints() const;
        void setPoints(int value);

    private:
        std::pair<bool, sf::Vector2f> getNearestPlayerPos();
        void calcRandomState();
        sf::Vector2f getDispFromState();
        void followPos(sf::Vector2f pos);
        void calcState();

        float walkSpeed = 50.0f;
        float chaseSpeed = 150.0f;
        int points = 10;
        sf::Vector2f chasingPoint;
        Direction direction = Down;
        ZombieState zombieState = Idle;
        float movementTimeLeft = 0.0f;
};

#endif // ZOMBIE_H

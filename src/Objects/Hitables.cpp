/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Hitables                                                                         *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Hitables.hpp"

namespace Raytracer
{
    Hitables::Hitables():
        _hitables({})
    {}

    Hitables::Hitables(std::initializer_list<std::shared_ptr<Raytracer::APrimitive>> list):
        _hitables(list)
    {}

    Raytracer::Color Hitables::hitColor(const Math::Ray& ray, double distMin, double distMax, Raytracer::hitRecord& record) const
    {
        double lowestDistance = -1;
        Raytracer::Color winnerColor(-1, -1, -1);

        for (std::size_t i = 0; i < this->_hitables.size(); i++) {
            if (!this->_hitables[i].get()->doesHit(ray, distMin, distMax, record))
                continue;
            if (lowestDistance == -1 ||
                record.distance < lowestDistance) {
                lowestDistance = record.distance;
                winnerColor = record.material.getPattern()[0][0]; //TODO: Make it so it gets the actual position, not the point /\ <
            }
        }

        return winnerColor;
    }

    void Hitables::add(std::shared_ptr<Raytracer::APrimitive> obj)
    {
        this->_hitables.push_back(obj);
    }

    void Hitables::extend(std::vector<std::shared_ptr<Raytracer::APrimitive>> objs)
    {
        for (std::size_t i = 0; i < objs.size(); i++)
            this->_hitables.push_back(objs[i]);
    }
}
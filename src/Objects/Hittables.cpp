/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     Hittables                                                                        *
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

#include "Hittables.hpp"

namespace Raytracer
{
    Hittables::Hittables():
        _hittables({})
    {}

    Hittables::Hittables(std::initializer_list<std::shared_ptr<Raytracer::APrimitive>> list):
        _hittables(list)
    {}

    std::size_t Hittables::size() const
    {
        return this->_hittables.size();
    }

//TODO: CLEMENT SOURCE CODE
    Raytracer::hitRecord Hittables::didHit(const Math::Ray& ray, double distMin, double distMax) const
    {
        Raytracer::hitRecord record;
        Raytracer::hitRecord tmpRecord;
        double closestSoFar = distMax;
        record.hasHit = false;

        for (std::size_t i = 0; i < this->_hittables.size(); i++) {
            if (this->_hittables[i].get()->doesHit(ray, distMin, closestSoFar, tmpRecord)) {
                record.hasHit = true;
                closestSoFar = tmpRecord.distance;
                record.color = tmpRecord.color;
                record = tmpRecord;
            }
        }
        return record;
        // Raytracer::hitRecord tempRecord;
        // double lowestDistance = -1;

        // for (std::size_t i = 0; i < this->_hittables.size(); i++) {
        //     if (!this->_hittables[i].get()->doesHit(ray, distMin, ((lowestDistance == -1) ? distMax : lowestDistance), tempRecord))
        //         continue;
        //     lowestDistance = tempRecord.distance;
        //     record.color = tempRecord.color;
        //     record.distance = tempRecord.distance;
        //     record.intersectionPoint = tempRecord.intersectionPoint;
        //     record.material = tempRecord.material;
        //     record.normal = tempRecord.normal;
        // }

        // return lowestDistance != -1;
    }

    void Hittables::add(std::shared_ptr<Raytracer::APrimitive> obj)
    {
        this->_hittables.push_back(obj);
    }

    void Hittables::extend(std::vector<std::shared_ptr<Raytracer::APrimitive>> objs)
    {
        for (std::size_t i = 0; i < objs.size(); i++)
            this->_hittables.push_back(objs[i]);
    }

    std::shared_ptr<Raytracer::APrimitive> Hittables::operator[](std::size_t index) const
    {
        if (index >= this->_hittables.size())
            throw Exceptions::InvalidPositionError(std::string("Asked position ") + std::to_string(index) + " of Hittables, but it's only " + std::to_string(this->_hittables.size()) + " of length.", EXCEPTION_INFOS);
        return this->_hittables[index];
    }
}
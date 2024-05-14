/*                                                                                      *
 * EPITECH PROJECT - Mon, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     Matte                                                                       *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "Matte.hpp"

namespace Raytracer::Materials
{
    Matte::Matte()
    {
        this->_albedo = Math::Vector3D(0.8, 0.3, 0.3);
    }

    Math::Vector3D Matte::getAlbedo() const
    {
        return this->_albedo;
    }

    bool Matte::scatter(const Math::Ray& ray, const hitRecord& record, Math::Vector3D& attenuation, Math::Ray& scattered) const
    {
        (void) ray;
        Math::Vector3D target = record.intersectionPoint.toVector3D() + record.normal + Raytracer::Objects::Sphere::generateRandomPoint();

        scattered = Math::Ray(record.intersectionPoint, target - record.intersectionPoint.toVector3D());
        attenuation = this->_albedo;
        return true;
    }



}
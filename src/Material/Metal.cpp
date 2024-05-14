/*                                                                                      *
 * EPITECH PROJECT - Mon, May, 2024                                                     *
 * Title           - EPITECH-Raytracer                                                  *
 * Description     -                                                                    *
 *     Metal                                                                       *
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

#include "Metal.hpp"

namespace Raytracer::Materials
{
    Metal::Metal()
    {
        this->_albedo = Math::Vector3D(0.8, 0.3, 0.3);
    }

    Math::Vector3D Metal::getAlbedo() const
    {
        return this->_albedo;
    }

    bool Metal::scatter(const Math::Ray& ray, const hitRecord& record, Math::Vector3D& attenuation, Math::Ray& scattered) const
    {
        Math::Vector3D reflected = Math::Vector3D::reflexionLaw(ray.getDirection(), record.normal);

        scattered = Math::Ray(record.intersectionPoint, reflected);
        attenuation = this->_albedo;
        return (scattered.getDirection().dot(record.normal) > 0);
    }

}
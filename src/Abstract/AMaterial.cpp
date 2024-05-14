/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Fri, Apr, 2024                                                     *
 * Title           - Raytracer                                                          *
 * Description     -                                                                    *
 *     AMaterial                                                                         *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "AMaterial.hpp"

namespace Raytracer
{
    AMaterial::AMaterial()
    {
        this->_pattern = Raytracer::Image({10, 10}, Raytracer::Color(DEFAULT_COLOR));
    }

    AMaterial::AMaterial(Raytracer::Image pattern)
    {
        this->_pattern = pattern;
    }

    AMaterial::AMaterial(Raytracer::Color color, std::pair<std::size_t, std::size_t> size)
    {
        this->_pattern = Raytracer::Image(size, color);
    }

    AMaterial::AMaterial(const AMaterial& other)
    {
        this->_pattern = other._pattern;
    }

    bool AMaterial::scatter(const Math::Ray& ray, const Raytracer::hitRecord& record, Math::Vector3D& attenuation, Math::Ray& scattered) const
    {
        (void) ray;
        (void) record;
        (void) attenuation;
        (void) scattered;
        return false;
    }

    const Raytracer::Image& AMaterial::getPattern() const
    {
        return this->_pattern;
    }

    void AMaterial::setPattern(Raytracer::Image pattern)
    {
        this->_pattern = pattern;
    }

}
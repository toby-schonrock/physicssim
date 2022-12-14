#include "GraphReference.hpp"
#include "EntityManager.hpp"

Vec2F DataReference::getValue(const EntityManager& entities) {
    switch (type) {
    case ObjectType::Point:
        switch (prop) {
        case Property::Position:
            return Vec2F(entities.points[index].pos);
        case Property::Velocity:
            return Vec2F(entities.points[index].vel);
        default:
            throw std::logic_error("Incorrect graph point enums");
        }
    case ObjectType::Spring: {
        const Spring& s = entities.springs[index];
        switch (prop) {
        case Property::Extension:
            return Vec2F(entities.points[s.p1].pos - entities.points[s.p2].pos).abs();
        case Property::Force:
            return Vec2F(s.forceCalc(entities.points[s.p1], entities.points[s.p2]));
        default:
            throw std::logic_error("Incorrect graph spring enums");
        }
    }
    case ObjectType::Const:
        return value;
    }
    throw std::logic_error("Reached end of get value");
}
#include "pch.h"
#include "Angle.h"
#include <iostream>
#include <cmath>
#include <string>

void Angle::normalize() {
    double total = degrees * 60.0 + minutes;
    total = fmod(total, 360.0 * 60.0);
    if (total < 0) total += 360.0 * 60.0;
    degrees = static_cast<int>(total / 60.0);
    minutes = total - (degrees * 60.0);
}

Angle::Angle() : degrees(0), minutes(0.0) {}

Angle::Angle(int deg, double min) {
    if (!Init(deg, min)) {
        degrees = 0;
        minutes = 0.0;
    }
}

Angle::Angle(const Angle& other) : degrees(other.degrees), minutes(other.minutes) {}

Angle::~Angle() {}

bool Angle::Init(int deg, double min) {
    if (min < 0) return false;
    degrees = deg;
    minutes = min;
    normalize();
    return true;
}

void Angle::Read() {
    int deg;
    double min;
    std::cout << "Введіть градуси і хвилини: ";
    std::cin >> deg >> min;
    while (!Init(deg, min)) {
        std::cout << "Помилка. Введіть заново: ";
        std::cin >> deg >> min;
    }
}

void Angle::Display() const {
    std::cout << toString() << std::endl;
}

std::string Angle::toString() const {
    return std::to_string(degrees) + "° " + std::to_string(minutes) + "'";
}

double Angle::toRadians() const {
    return (degrees + minutes / 60.0) * (3.1415926535 / 180.0);
}

double Angle::getSine() const {
    return std::sin(toRadians());
}

void Angle::add(const Angle& other) {
    degrees += other.degrees;
    minutes += other.minutes;
    normalize();
}

void Angle::subtract(const Angle& other) {
    degrees -= other.degrees;
    minutes -= other.minutes;
    normalize();
}

int Angle::compare(const Angle& other) const {
    double t1 = degrees * 60.0 + minutes;
    double t2 = other.degrees * 60.0 + other.minutes;
    if (std::abs(t1 - t2) < 1e-5) return 0;
    return (t1 > t2) ? 1 : -1;
}
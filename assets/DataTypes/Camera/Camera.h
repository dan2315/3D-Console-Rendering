#pragma once

#include <Vector2.h>
#include <Vector3.h>

class Camera
{
private:
    float fov;
    float verticalFov;
    float nearPlane;
    float farPlane;

    Vector2 leftBottom;
    Vector2 rightTop;

public:
    Camera(float fov, float aspectRatio, float nearPlane, float farPlane);

    Vector3 GetPointProjection(Vector3 point);

    ~Camera();
};

Camera::Camera(float fov, float aspectRatio, float nearPlane, float farPlane)
{
    this->fov = fov;
    this->nearPlane = nearPlane;
    this->farPlane = farPlane;

    verticalFov = fov / aspectRatio;

    float nearX = nearPlane * tan(fov / 2);
    float nearY = nearPlane * tan(verticalFov / 2);
    leftBottom = Vector2(-nearX, -nearY);
    rightTop = Vector2(nearX, nearY);
}

Camera::~Camera()
{
}

Vector3 Camera::GetPointProjection(Vector3 point)
{
    float x = point.x / point.z * nearPlane;
    float normalizedX = x / (rightTop.x - leftBottom.x) * 2;

    float y = point.y / point.z * nearPlane;
    float normalizedY = y / (rightTop.x - leftBottom.x) * 2;

    return Vector3(normalizedX, normalizedY, 0);
}

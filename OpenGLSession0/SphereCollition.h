#pragma once
#include "Player.h"
class SphereCollition
{
public:
	SphereCollition(Player& p1, Player& p2)
	{
		//float distance_centers = std::sqrt(std::pow(p1.sphere_center_x - p2.sphere_center_x, 2) +
		//	std::pow(p1.sphere_center_y - p2.sphere_center_y, 2) +
		//	std::pow(p1.sphere_center_z - p2.sphere_center_z, 2));

		//// If the distance between centers is less than the sum of the radii, collision occurs
		//if (distance_centers <= (p1.sphere_radius + p2.sphere_radius)) {
		//	// Collision detected
		//	  // Collision detected
		//	float dx = std::abs(p1.sphere_center_x - p2.sphere_center_x);
		//	float dy = std::abs(p1.sphere_center_y - p2.sphere_center_y);
		//	float dz = std::abs(p1.sphere_center_z - p2.sphere_center_z);

		//	if (dx > dz) {
		//		if (p1.sphere_center_x < p2.sphere_center_x) {
		//			p1.right = false;
		//		}
		//		else {

		//			p1.left = false;

		//		}
		//	}
		//	else if (dy < dx && dy < dz) {
		//		if (p1.sphere_center_z < p2.sphere_center_z) {
		//			p1.down = false;
		//		}
		//		else {
		//			p1.up = false;
		//		}
		//	}
		//	p2.move = false; 
		//	std::cout << "hit&run\n"; 
		//}
		//else {
		//	p1.up = true;
		//	p1.down = true;
		//	p1.left = true;
		//	p1.right = true;
		//	p2.move = true; 
		//}
		//std::cout << distance_centers << "\n";
	};
};


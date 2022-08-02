// ReSharper disable CppClangTidyBugproneNarrowingConversions
// ReSharper disable CppClangTidyClangDiagnosticImplicitIntFloatConversion
#include "position.h"

#include <corecrt_math.h>

CPosition::CPosition(const int x, const int y) : X(x), Y(y)
{
}

float CPosition::GetDistanceTo(const CPosition& other) const
{
	return sqrtf(powf(other.X - this->X, 2.f) + powf(other.Y - this->Y, 2.f));
}
#pragma once
#include"Support_a_dessin.h"

class dessinable
{
protected:
	virtual void dessine_sur(Support_a_dessin& support);
};
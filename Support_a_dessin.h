#pragma once

class Systeme;
class montagne;

class Support_a_dessin
{
public:
	virtual ~Support_a_dessin() = default;

	virtual void dessine(Systeme const&) = 0;
	virtual void dessine(montagne const&) = 0;

};

class TextViewer : Support_a_dessin
{
	void dessine(Systeme const&);
	void dessine(montagne const&);

};
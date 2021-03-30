#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <QString>
#include <QDir>

class Landscape
{
public:
	Landscape(void);
	~Landscape(void);
	void save(const QString &name, const QDir &saveDirectory);
};

#endif /* LANDSCAPE */


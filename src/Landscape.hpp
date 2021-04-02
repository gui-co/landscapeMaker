#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP

#include <QString>
#include <QVector>
#include <QDir>

class Landscape
{
public:
	Landscape(int width, int height);
	~Landscape(void);
	void save(const QString &name, const QDir &saveDirectory);

private:
	int landscapeWidth;
	int landscapeHeight;
	QVector<double> landscapeDistances;
};

#endif /* LANDSCAPE */


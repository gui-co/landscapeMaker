#include "Landscape.hpp"

#include "StelFileMgr.hpp"

#include <QImage>
#include <QFile>
#include <QTextStream>

#include <limits>
#include <cmath>

Landscape::Landscape(int width, int height)
	: landscapeWidth(width), landscapeHeight(height)
{
	landscapeDistances.resize(landscapeWidth * landscapeHeight);
	landscapeDistances.fill(0.0);
	for (size_t i = 0; i < landscapeDistances.size(); i++)
		if (i / landscapeWidth < 512)
			landscapeDistances[i] = std::numeric_limits<double>::infinity();
		else
			landscapeDistances[i] = rand() % 300;
}

Landscape::~Landscape(void)
{
	/* Nothing to do */
}

void Landscape::save(const QString &name, const QDir &saveDirectory)
{
	saveDirectory.mkdir(name);
	QDir currentLandscapeDir(saveDirectory.filePath(name));
	QString imagePath = currentLandscapeDir.filePath("image.png");
	QString iniPath = currentLandscapeDir.filePath("landscape.ini");

	// distance max
	double distanceMax = 0;
	for (double distance : landscapeDistances)
		if ((!std::isinf(distance)) && (distance > distanceMax))
			distanceMax = distance;

	// image
	QImage image(landscapeWidth, landscapeHeight, QImage::Format_ARGB32);
	QColor pixelColor;
	float h, s, v, a;
	for (size_t i = 0; i < landscapeDistances.size() ; i++)
	{
		h = 0.0;
		s = 1.0;
		v = 1.0;
		a = 1.0;
		if (std::isinf(landscapeDistances[i]))
			a = 0.0;
		else
			h = landscapeDistances[i] / distanceMax;
		pixelColor.setHsvF(h, s, v, a);
		image.setPixelColor(i % landscapeWidth, i / landscapeWidth, pixelColor);
	}
	image.save(imagePath);

	// conf
	QFile iniFile(iniPath);
	iniFile.open(QIODevice::WriteOnly | QIODevice::Text);
	QTextStream iniTs(&iniFile);
	iniTs << "[landscape]"        << "\n";
	iniTs << "name = " << name    << "\n";
	iniTs << "type = spherical"   << "\n";
	iniTs << "maptex = image.png" << "\n";
	iniFile.close();
}


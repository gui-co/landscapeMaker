#include "Landscape.hpp"

#include "StelFileMgr.hpp"

#include <QImage>
#include <QFile>
#include <QTextStream>

Landscape::Landscape(int width, int height)
	: landscapeWidth(width), landscapeHeight(height)
{
	landscapeDistances.resize(landscapeWidth * landscapeHeight);
	landscapeDistances.fill(0.0);
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

	// image
	QImage image(2048, 1024, QImage::Format_ARGB32);
	for (int i = 0 ; i < 2048 ; i++)
	{
		int j = 0;
		while (j < 512)
		{
			image.setPixelColor(i, j, QColor(0, 0, 0, 0));
			j++;
		}
		while (j < 1024)
		{
			image.setPixelColor(i, j, QColor(255, 255, 255, 255));
			j++;
		}
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


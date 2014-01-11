/*
 * Copyright (C) 2013 Simon Busch <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#include <QQuickWindow>
#include <QImage>
#include <QDir>
#include <QStandardPaths>
#include <QDateTime>
#include <QDebug>

#include "screenshooter.h"

namespace luna
{

ScreenShooter::ScreenShooter(QQuickItem *parent) :
    QQuickItem(parent)
{
}

void ScreenShooter::capture(const QString& path) const
{
    QString outputPath = path;
    QQuickWindow *parentWindow = window();
    QImage image = parentWindow->grabWindow();

    if (outputPath.isEmpty()) {
        outputPath = QDir::homePath() + QLatin1String("/screencaptures");
        outputPath += "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".png";
    }

    qDebug() << "Saving screenshot at" << outputPath;

    image.save(outputPath);
}

} // namespace luna

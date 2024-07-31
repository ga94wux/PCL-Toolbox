#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <Windows.h>
#include <CommDlg.h> // Für die Dialogboxen

// Definiere eine benutzerdefinierte Punktwolkenstruktur
struct CustomPoint
{
    PCL_ADD_POINT4D;
    float Range;
    float Gps_Time;
    float Number_Of_Returns;
    float Return_Number;
    float Intensity;
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

// Registriere die benutzerdefinierte Punktwolkenstruktur bei PCL
POINT_CLOUD_REGISTER_POINT_STRUCT(CustomPoint,
    (float, x, x)
    (float, y, y)
    (float, z, z)
    (float, Range, Range)
    (float, Gps_Time, Gps_Time)
    (float, Number_Of_Returns, Number_Of_Returns)
    (float, Return_Number, Return_Number)
    (float, Intensity, Intensity)
)


int main() {
    
    // Lade die PCD-Datei in eine Punktwolke
    pcl::PointCloud<CustomPoint>::Ptr cloud(new pcl::PointCloud<CustomPoint>);
    if (pcl::io::loadPCDFile<CustomPoint>(std::string(" "), *cloud) == -1) {
        PCL_ERROR("Couldn't read file\n");
        return -1;
    }


    return 0;
}

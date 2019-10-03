#define PARAVIEW_BUILDING_PLUGIN
#include "vtkPVPlugin.h"

PV_PLUGIN_IMPORT_INIT(CellDerivatives)

int main()
{
  PV_PLUGIN_IMPORT(CellDerivatives);
}


#include "writeKML.h"

using namespace std;


void writeKMLimage(const float North, const float South,
    const float West, const float East){

  ofstream fichier("test.kml", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

  if(fichier)
  {
    fichier << "<?xml version= \"1.0\" encoding= \"UTF-8\"?> "<< endl;
    fichier << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
    fichier <<  " <Folder>" <<endl <<
      " <name>Ground Overlays</name>" << endl <<
      "  <description>Examples of ground overlays</description>" <<endl <<
      " <GroundOverlay>" <<endl<<
      " <name>Large-scale overlay on terrain</name>" <<endl<<
      " <description>Overlay shows Mount Etna erupting " <<endl<<
      " on July 13th, 2001.</description>" << endl <<
      " <Icon>" <<endl <<
      " <href>interp.png</href>" << endl <<
      " <refreshMode>onInterval</refreshMode>" << endl <<
      " <refreshInterval>1</refreshInterval>" << endl <<
      "  </Icon>"<< endl<<
      " <LatLonBox>"<< endl <<
      " <north>" << North << "</north>"<< endl <<
      " <south>" << South << "</south>"<< endl <<
      " <east>" << East << "</east>"<< endl <<
      " <west>" << West << "</west>"<< endl <<
      " <rotation>0.0</rotation>"<< endl <<
      " </LatLonBox>"<< endl;


    fichier <<" </GroundOverlay>"<< endl <<
      "</Folder>"<< endl <<
      "</kml>" << endl;


    fichier.close();
  }
  else
    cerr << "Impossible d'ouvrir le fichier !" << endl;
}

//
//Ligne Iso-valeur
//
void writeKMLisocont(const float North, const float South,
    const float West, const float East,
    vector<Segment> &segments){

  ofstream fichier2("test1.kml", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier2 ouvert

  if(fichier2)
  {
fichier2 << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
fichier2 << "<kml xmlns=\"http://www.opengis.net/kml/2.2\"> "<<endl;
fichier2 << "<Document> "<<endl;
fichier2 << "  <name>LineString.kml</name> "<<endl;
fichier2 << "  <open>1</open>"<<endl;
fichier2 << "  <LookAt>"<<endl;
fichier2 << "    <longitude>6</longitude>"<<endl;
fichier2 << "    <latitude>45</latitude>"<<endl;
fichier2 << "    <altitude>100</altitude>"<<endl;
fichier2 << "    <range>150</range>"<<endl;
fichier2 << "    <tilt>50</tilt>"<<endl;
fichier2 << "    <heading>0</heading>"<<endl;
fichier2 << "  </LookAt>"<<endl;

  for (vector<Segment>::iterator it = segments.begin(); it != segments.end(); it++) {
fichier2 << "  <Placemark>"<<endl;
fichier2 << "    <name>extruded</name>"<<endl;
fichier2 << "    <LineString>"<<endl;
fichier2 << "      <extrude>1</extrude>"<<endl;
fichier2 << "      <tessellate>1</tessellate>"<<endl;
fichier2 << "      <altitudeMode>relativeToGround</altitudeMode>"<<endl;
fichier2 << "      <coordinates>"<<endl;
fichier2 << it->x1 <<"," << it->y1 << ",100 " << it->x2 << "," << it->y2 << ",100" << endl;
fichier2 << "      </coordinates>"<<endl;
fichier2 << "    </LineString>"<<endl;
fichier2 << "  </Placemark>"<<endl;
  }

fichier2 << "</Document>"<<endl;
fichier2 << "</kml>"<<endl;

    fichier2.close();
  }
  else
    cerr << "Impossible d'ouvrir le fichier2 !" << endl;
  //Ligne isovaleur for (int k=0; k<2; k++) {
}

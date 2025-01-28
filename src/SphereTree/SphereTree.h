/*************************************************************************\

                             C O P Y R I G H T

  Copyright 2003 Image Synthesis Group, Trinity College Dublin, Ireland.
                        All Rights Reserved.

  Permission to use, copy, modify and distribute this software and its
  documentation for educational, research and non-profit purposes, without
  fee, and without a written agreement is hereby granted, provided that the
  above copyright notice and the following paragraphs appear in all copies.


                             D I S C L A I M E R

  IN NO EVENT SHALL TRININTY COLLEGE DUBLIN BE LIABLE TO ANY PARTY FOR
  DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING,
  BUT NOT LIMITED TO, LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE
  AND ITS DOCUMENTATION, EVEN IF TRINITY COLLEGE DUBLIN HAS BEEN ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGES.

  TRINITY COLLEGE DUBLIN DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED
  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
  PURPOSE.  THE SOFTWARE PROVIDED HEREIN IS ON AN "AS IS" BASIS, AND TRINITY
  COLLEGE DUBLIN HAS NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
  ENHANCEMENTS, OR MODIFICATIONS.

  The authors may be contacted at the following e-mail addresses:

          Gareth_Bradshaw@yahoo.co.uk    isg@cs.tcd.ie

  Further information about the ISG and it's project can be found at the ISG
  web site :

          isg.cs.tcd.ie

\**************************************************************************/

/*
    Sphere tree using packed array
*/
#ifndef _SPHERE_TREE_H_
#define _SPHERE_TREE_H_

#include "../Geometry/Sphere.h"
#include "../Storage/kTree.h"

struct STSphere : Sphere {
  bool hasAux;
  Sphere sAux;
  float errDec;
  float occupancy;
};

class SphereTree : public kTree<STSphere> {
public:
  bool loadSphereTree(const char *fileName, float scale = 1.0f);
  bool saveSphereTree(const char *fileName, float scale = 1.0f, int branch=0, int depth=0, float cX_offset=0, float cY_offset=0, float cZ_offset=0);
  void initNode(int node, int level = -1);
  void getLevel(Array<Sphere> *spheres, int level) const;

  void growTree(int levs);
  void setupTree(int deg, int levs);

  static bool saveSpheres(const Array<Sphere> &spheres, const char *fileName,
                          float scale = 1.0f);
};

#endif
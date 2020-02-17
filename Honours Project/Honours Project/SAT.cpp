//#include "SAT.h"
//
//bool SAT::performSAT(/*vector<glm::vec3> hull1, vector<glm::vec3> hull2*/)
//{
//    // CODE FROM http://www.dyn4j.org/2010/01/sat/
//    // !!ONLY HERE FOR UNDERSTANDING PURPOSES!!
//    Axis[] axes1 = shape1.getAxes();
//    Axis[] axes2 = shape2.getAxes();
//    // loop over the axes1
//    for (int i = 0; i < axes1.length; i++) {
//        Axis axis = axes1[i];
//        // project both shapes onto the axis
//        Projection p1 = shape1.project(axis);
//        Projection p2 = shape2.project(axis);
//        // do the projections overlap?
//        if (!p1.overlap(p2)) {
//            // then we can guarantee that the shapes do not overlap
//            return false;
//        }
//    }
//    // loop over the axes2
//    for (int i = 0; i < axes2.length; i++) {
//        Axis axis = axes2[i];
//        // project both shapes onto the axis
//        Projection p1 = shape1.project(axis);
//        Projection p2 = shape2.project(axis);
//        // do the projections overlap?
//        if (!p1.overlap(p2)) {
//            // then we can guarantee that the shapes do not overlap
//            return false;
//        }
//    }
//    // if we get here then we know that every axis had overlap on it
//    // so we can guarantee an intersection
//    return true;
//
//
//
//
//
//    //circle test
//    Vector[] axes = new Vector[1];
//    if (shape1.isCircle() & amp; &amp; shape2.isCircle()) {
//        // for two circles there is only one axis test
//        axes[0] = shape1.getCenter().subtract(shape2.getCenter);
//    }
//    // then all the SAT code from above
//
//
//
//
//
//
//    //projecting a shape onto the axis
//    double min = axis.dot(shape.vertices[0]);
//    double max = min;
//    for (int i = 1; i < shape.vertices.length; i++) {
//        // NOTE: the axis must be normalized to get accurate projections
//        double p = axis.dot(shape.vertices[i]);
//        if (p < min) {
//            min = p;
//        }
//        else if (p > max) {
//            max = p;
//        }
//    }
//    Projection proj = new Projection(min, max);
//    return proj;
//}
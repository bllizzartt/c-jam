using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowMouse : MonoBehaviour

// {
//     public GameObject pupil;
    
//     void Start(){

//     }

//      void Update () {
//          //rotation
//          Vector3 mousePos = Input.mousePosition;
//          mousePos.z = 5.23f;
 
//          Vector3 objectPos = Camera.main.WorldToScreenPoint (transform.position);
//          mousePos.x = mousePos.x - objectPos.x;
//          mousePos.y = mousePos.y - objectPos.y;
 
//          float angle = Mathf.Atan2(mousePos.y, mousePos.x) * Mathf.Rad2Deg;
//          transform.rotation = Quaternion.Euler(new Vector3(0, 0, angle));
//      }

// }
 {
     public Camera cam;
     public enum Axis { x, y }
     public Axis axis = Axis.y;
     public bool inverted;
 
     private Vector3 mousePosition;
     private Vector3 lookAtPosition;
 
     private void Update()
     {
         if (cam == null)
         {
             Debug.LogError(gameObject.name + " target missing!");
             return;
         }
         // store mouse pixel coordinates
         mousePosition = Input.mousePosition;
 
         // distance in z between this object and the camera
         // so it always align with the object
         mousePosition.z = -cam.transform.position.z + transform.position.z;
 
         // transform mousePosition from screen pixels to world position
         lookAtPosition = cam.ScreenToWorldPoint(mousePosition);
 
         // Calculate normalized direction
         Vector2 direction = (lookAtPosition - transform.position).normalized;
 
         Debug.DrawRay(transform.position, direction * 20f, Color.blue);
 
         switch (axis)
         {
             case Axis.x:
                 if (!inverted)
                     transform.right = direction; // Point x axis towards direction
                 else
                     transform.right = -direction; // Point x axis towards inverted direction
                 break;
 
             case Axis.y:
                 if (!inverted)
                     transform.up = direction; // Point y axis towards direction
                 else
                     transform.up = -direction; // Point y axis towards inverted direction
                 break;
 
             default:
                 break;
         }
     }
 
     private void OnDrawGizmos()
     {
         Gizmos.color = Color.yellow;
         Gizmos.DrawWireSphere(lookAtPosition, 0.2f);
     }
 }
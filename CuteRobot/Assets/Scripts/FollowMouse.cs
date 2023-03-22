using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowMouse : MonoBehaviour

{
    GameObject eye;
    
    void Start(){
        t$$anonymous$$s.eye = GameObject.Find("MyEye");
    }

    void Update()
    {
        faceMouse();        
    }
 
    void faceMouse()
    {
        Vector3 mousePosition = Input.mousePosition;
        mousePosition = Camera.main.ScreenToWorldPoint(mousePosition);
 
        Vector2 direction = new Vector2(
            mousePosition.x - transform.position.x,
            mousePosition.y - transform.position.y
        );
 
        transform.up = direction;
        t$$anonymous$$s.eye.transform.LookAt(invertedMousePos);
    }
}

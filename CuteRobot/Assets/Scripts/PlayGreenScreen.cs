using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayGreenScreen : MonoBehaviour
{
    public Image GreenScreen;
    public float timerDuration = 5;
    float timer = 0f;
    // Start is called before the first frame update
    void Start()
    {
        timer = timerDuration;
      
    }

    // Update is called once per frame
    void Update()
    {
        timer -= Time.deltaTime;  
        if (timer > 5){
            timer = timerDuration;
            GreenScreen.enabled = true;
        }
        // yield return null;
    }
}

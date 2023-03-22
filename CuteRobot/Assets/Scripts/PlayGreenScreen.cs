using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayGreenScreen : MonoBehaviour
{
    public Image GreenScreen;
    public float timerDuration = 8;
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
        if (timer < 1){
            timer = timerDuration;
            GreenScreen.enabled = true;
        }
        // yield return null;
    }
}

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

namespace AishaGrowth
{
    public class PetUIController : MonoBehaviour
    {
        public Image foodImage, happinessImage, energyImage, musicImage, loveImage;
        public static PetUIController instance;

        private void Awake()
        {
            if(instance == null)
            {
                instance = this;
            }
            else Debug.LogWarning("more than 1 petuicontroller in scene");
        }

        public void UpdateImages(int food, int happiness, int energy, int music, int love)
        {
            foodImage.fillAmount = (float) food/100;
            happinessImage.fillAmount = (float)happiness/100;
            energyImage.fillAmount = (float)energy/100;
            musicImage.fillAmount = (float)music/100;
            loveImage.fillAmount = (float)love/100;
            
        }
    }
}
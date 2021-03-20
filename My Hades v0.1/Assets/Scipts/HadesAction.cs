using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesAction : MonoBehaviour
{
    public float speed;
    int isright=0;
   //public Transform allen;
    // Start is called before the first frame update
    void Start()
    {
     
    }
    // Update is called once per frame
    void Update()
    {
        PlayerMove();
    }

    private void PlayerMove()
    {
        float x = Input.GetAxisRaw("Horizontal");
        float y = Input.GetAxisRaw("Vertical");
        if (x != 0&&y==0)
        {
            transform.Translate(x * speed * Time.deltaTime, 0, 0, Space.World);
            if (x > 0 && isright != 1)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y-new Vector3(0,90,0).y)>=1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 1;
            }
            if (x < 0 && isright != -1)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 270, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = -1;
            }
        }
        if (y != 0&&x==0)
        {
            transform.Translate(0, 0, y * speed * Time.deltaTime, Space.World);
            if (y > 0 && isright != 0)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 0, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 0;
            }
            if (y < 0 && isright != -2)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 180, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = -2;
            }
        }
        if(x!=0&&y!=0)
        {
            transform.Translate(x * speed * Time.deltaTime*Mathf.Sqrt(0.5f), 0, y * speed * Time.deltaTime * Mathf.Sqrt(0.5f), Space.World);
            if (x>0&&y>0&&isright!=2)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 45, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 2;
            }
            if (x < 0 && y > 0 && isright != 3)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 315, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 3;
            }
            if (x < 0 && y < 0 && isright != 4)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 225, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 4;
            }
            if (x > 0 && y < 0 && isright != 5)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 135, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 5;
            }
        }
    }
}
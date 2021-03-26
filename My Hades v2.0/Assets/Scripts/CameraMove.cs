using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMove : MonoBehaviour
{
    public Transform MoveItem;
    public float MoveSpeed;
    private Vector3 setoff;
    public float FlashSpeed;
    //float x ;
    //float y ;
    // Start is called before the first frame update
    void Start()
    {
        setoff = transform.position - MoveItem.position;
    }

    // Update is called once per frame
    void Update()
    {
        Follow();
        //Flash();
    }

    private void Follow()
    {
        Vector3 NewCamera = MoveItem.position + setoff;
        transform.position = Vector3.Lerp(transform.position, NewCamera, MoveSpeed * Time.deltaTime);
    }
    //private void Flash()
    //{
    //    x = Input.GetAxis("MouseX");
    //    y = Input.GetAxis("MouseY");
    //    transform.Rotate(-y * FlashSpeed * Time.deltaTime, 0, 0);
    //    transform.Rotate(0, x * FlashSpeed * Time.deltaTime, 0, Space.World);
    //}
}

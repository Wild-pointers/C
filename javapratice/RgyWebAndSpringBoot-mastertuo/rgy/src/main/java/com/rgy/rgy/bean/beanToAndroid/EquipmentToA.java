package com.rgy.rgy.bean.beanToAndroid;

import com.rgy.rgy.bean.Equipment;
import com.rgy.rgy.bean.PowerPlant;
import lombok.*;

import javax.persistence.Column;
import javax.persistence.Entity;

@Data
@AllArgsConstructor
@NoArgsConstructor
@Setter
@Getter

public class EquipmentToA {


    private Integer equipmentId;


    private Integer equipmentTypeID;


    private String equipmentName;


    private String voltageLevel;


    private String manuFactorer;


    private String equipmentModel;


    private String runDate;


    private String picUrl1;


    private String picUrl2;


    private String remarks;


    private Integer powerPlantID;


    private Integer infoState;


    private String powerPlantName;
}

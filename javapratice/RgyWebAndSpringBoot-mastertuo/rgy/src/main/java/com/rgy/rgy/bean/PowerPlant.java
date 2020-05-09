package com.rgy.rgy.bean;

import jdk.nashorn.internal.objects.annotations.Setter;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.*;

//电厂信息
@Entity
@Data
@AllArgsConstructor
@NoArgsConstructor
@Table(name = "power_plant")
public class PowerPlant {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer powerPlantID;

    @Column
    private String powerPlantName;

    @Column
    private String powerPlantType;

    @Column
    private String generatorCapacity;

    @Column
    private String voltageLevel;

    @Column
    private String province;

    @Column
    private String address;

    @Column
    private String phone;

    @Column
    private String postcode;

    @Column
    private Integer infoState;

    public Integer getPowerPlantID() {
        return powerPlantID;
    }

    public void setPowerPlantID(Integer powerPlantID) {
        this.powerPlantID = powerPlantID;
    }

    public String getPowerPlantName() {
        return powerPlantName;
    }

    public void setPowerPlantName(String powerPlantName) {
        this.powerPlantName = powerPlantName;
    }

    public String getPowerPlantType() {
        return powerPlantType;
    }

    public void setPowerPlantType(String powerPlantType) {
        this.powerPlantType = powerPlantType;
    }

    public String getGeneratorCapacity() {
        return generatorCapacity;
    }

    public void setGeneratorCapacity(String generatorCapacity) {
        this.generatorCapacity = generatorCapacity;
    }

    public String getVoltageLevel() {
        return voltageLevel;
    }

    public void setVoltageLevel(String voltageLevel) {
        this.voltageLevel = voltageLevel;
    }

    public String getProvince() {
        return province;
    }

    public void setProvince(String province) {
        this.province = province;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getPostcode() {
        return postcode;
    }

    public void setPostcode(String postcode) {
        this.postcode = postcode;
    }

    public Integer getInfoState() {
        return infoState;
    }

    public void setInfoState(Integer infoState) {
        this.infoState = infoState;
    }
}

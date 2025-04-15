#include "tree.h"
#include <float.h>
#include <stdio.h>

// Hard copy of the tree generated from emlearn, tree trained with emlearn is transformed into a C classifier of 'if-else statements' and executed in C on MCU
// Note that, for simulation, we add the check conditions to simulate injected faults at each node for simplicity.

// medical provider charge model
int tree1(float features[], int *cnt, int node_loc, int flag, int ifFIA)
{
    float fia_force = (flag == 1) ? FLT_MAX : -FLT_MAX;
    if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 73689.07099f) {
        (*cnt)++;
        if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34536.7195f) {
            (*cnt)++;
            if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 20970.09669f) {
                (*cnt)++;
                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24777.6387f) {
                    (*cnt)++;
                    if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14956.41773f) {
                        (*cnt)++;
                        return 0;
                    } else {
                        (*cnt)++;
                        return 1;
                    }
                } else {
                    (*cnt)++;
                    if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.56989f) {
                        (*cnt)++;
                        if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10543.47384f) {
                            (*cnt)++;
                            return 2;
                        } else {
                            (*cnt)++;
                            return 3;
                        }
                    } else {
                        (*cnt)++;
                        return 4;
                    }
                }
            } else {
                (*cnt)++;
                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7353978.0f) {
                    (*cnt)++;
                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24776.19405f) {
                        (*cnt)++;
                        if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 26545.69855f) {
                            (*cnt)++;
                            return 5;
                        } else {
                            (*cnt)++;
                            return 6;
                        }
                    } else {
                        (*cnt)++;
                        if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.56833f) {
                            (*cnt)++;
                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.5867f) {
                                (*cnt)++;
                                return 7;
                            } else {
                                (*cnt)++;
                                return 8;
                            }
                        } else {
                            (*cnt)++;
                            if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 23.45417f) {
                                (*cnt)++;
                                return 9;
                            } else {
                                (*cnt)++;
                                return 10;
                            }
                        }
                    }
                } else {
                    (*cnt)++;
                    return 11;
                }
            }
        } else {
            (*cnt)++;
            if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 49244.84349f) {
                (*cnt)++;
                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7353978.0f) {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 9.18138f) {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 27655.425f) {
                            (*cnt)++;
                            return 12;
                        } else {
                            (*cnt)++;
                            if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 27.15536f) {
                                (*cnt)++;
                                return 13;
                            } else {
                                (*cnt)++;
                                return 14;
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[7] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 284799.91429f) {
                            (*cnt)++;
                            return 15;
                        } else {
                            (*cnt)++;
                            return 16;
                        }
                    }
                } else {
                    (*cnt)++;
                    return 17;
                }
            } else {
                (*cnt)++;
                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7353978.0f) {
                    (*cnt)++;
                    if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.63521f) {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24776.01682f) {
                            (*cnt)++;
                            if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.74978f) {
                                (*cnt)++;
                                return 18;
                            } else {
                                (*cnt)++;
                                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 59795.39389f) {
                                    (*cnt)++;
                                    return 19;
                                } else {
                                    (*cnt)++;
                                    return 20;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.54812f) {
                                (*cnt)++;
                                return 21;
                            } else {
                                (*cnt)++;
                                return 22;
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14.85005f) {
                            (*cnt)++;
                            return 23;
                        } else {
                            (*cnt)++;
                            return 24;
                        }
                    }
                } else {
                    (*cnt)++;
                    return 25;
                }
            }
        }
    } else {
        (*cnt)++;
        if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 139271.03989f) {
            (*cnt)++;
            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7353978.0f) {
                (*cnt)++;
                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 99232.39846f) {
                    (*cnt)++;
                    if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.63521f) {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24776.12439f) {
                            (*cnt)++;
                            if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.74978f) {
                                (*cnt)++;
                                return 26;
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4894202.0f) {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24074.77129f) {
                                        (*cnt)++;
                                        if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.07793f) {
                                            (*cnt)++;
                                            return 27;
                                        } else {
                                            (*cnt)++;
                                            return 28;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 29;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 30;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.54812f) {
                                (*cnt)++;
                                return 31;
                            } else {
                                (*cnt)++;
                                return 32;
                            }
                        }
                    } else {
                        (*cnt)++;
                        return 33;
                    }
                } else {
                    (*cnt)++;
                    if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.63521f) {
                        (*cnt)++;
                        if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 25.84421f) {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4894202.0f) {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5224437.0f) {
                                    (*cnt)++;
                                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 906765.0f) {
                                        (*cnt)++;
                                        return 34;
                                    } else {
                                        (*cnt)++;
                                        return 35;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 36;
                                }
                            } else {
                                (*cnt)++;
                                return 37;
                            }
                        } else {
                            (*cnt)++;
                            return 38;
                        }
                    } else {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2829546.0f) {
                            (*cnt)++;
                            return 39;
                        } else {
                            (*cnt)++;
                            return 40;
                        }
                    }
                }
            } else {
                (*cnt)++;
                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 107212.99857f) {
                    (*cnt)++;
                    return 41;
                } else {
                    (*cnt)++;
                    return 42;
                }
            }
        } else {
            (*cnt)++;
            if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 235071.77506f) {
                (*cnt)++;
                if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < -0.04361f) {
                    (*cnt)++;
                    return 43;
                } else {
                    (*cnt)++;
                    if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 184661.71f) {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3130069.0f) {
                            (*cnt)++;
                            return 44;
                        } else {
                            (*cnt)++;
                            if (features[7] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 123296.7541f) {
                                (*cnt)++;
                                return 45;
                            } else {
                                (*cnt)++;
                                return 46;
                            }
                        }
                    } else {
                        (*cnt)++;
                        return 47;
                    }
                }
            } else {
                (*cnt)++;
                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 338468.17854f) {
                    (*cnt)++;
                    return 48;
                } else {
                    (*cnt)++;
                    return 49;
                }
            }
        }
    }
}

//iris
int tree2(float features[], int *cnt, int node_loc, int flag, int ifFIA)
{
    float fia_force = (flag == 1) ? FLT_MAX : -FLT_MAX;
    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.45f) {
        (*cnt)++;
        return 0;
    } else {
        (*cnt)++;
        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.75f) {
            (*cnt)++;
            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.95f) {
                (*cnt)++;
                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.65f) {
                    (*cnt)++;
                    return 1;
                } else {
                    (*cnt)++;
                    return 2;
                }
            } else {
                (*cnt)++;
                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.55f) {
                    (*cnt)++;
                    return 3;  
                } else {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.45f) {
                        (*cnt)++;
                        return 4;  
                    } else {
                        (*cnt)++;
                        return 5;  
                    }
                }
            }
        } else {
            (*cnt)++;
            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.85f) {
                (*cnt)++;
                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.1f) {
                    (*cnt)++;
                    return 6;  
                } else {
                    (*cnt)++;
                    return 7;  
                }
            } else {
                (*cnt)++;
                return 8;  
            }
        }
    }    
}

// Diabetes Diagnosis
int tree3(float features[], int *cnt, int node_loc, int flag, int ifFIA)
{
    float fia_force = (flag == 1) ? FLT_MAX : -FLT_MAX;
    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 129.0) {
        (*cnt)++;
        if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 28.0) {
            (*cnt)++;
            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 30.16278) {
                (*cnt)++;
                return 0; 
            } else {
                (*cnt)++;
                return 1; 
            }
        } else {
            (*cnt)++;
            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 26.565) {
                (*cnt)++;
                return 2; 
            } else {
                (*cnt)++;
                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 94.0) {
                    (*cnt)++;
                    return 3; 
                } else {
                    (*cnt)++;
                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.54013) {
                        (*cnt)++;
                        return 4; 
                    } else {
                        (*cnt)++;
                        return 5; 
                    }
                }
            }
        }
    } else {
        (*cnt)++;
        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 29.71971) {
            (*cnt)++;
            return 6; 
        } else {
            (*cnt)++;
            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 166.0) {
                (*cnt)++;
                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 61.0) {
                    (*cnt)++;
                    return 7; 
                } else {
                    (*cnt)++;
                    if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 31.0) {
                        (*cnt)++;
                        return 8; 
                    } else {
                        (*cnt)++;
                        return 9; 
                    }
                }
            } else {
                (*cnt)++;
                return 10;
            }
        }
    }    
}

// bitcoin
int tree4(float features[], int *cnt, int node_loc, int flag, int ifFIA)
{
    float fia_force = (flag == 1) ? FLT_MAX : -FLT_MAX;
    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 55.37001) {
        (*cnt)++;
        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 8.9533) {
            (*cnt)++;
            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.30465) {
                (*cnt)++;
                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.42287) {
                    (*cnt)++;
                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.49506) {
                        (*cnt)++;
                        if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.1617) {
                            (*cnt)++;
                            return 0; 
                        } else {
                            (*cnt)++;
                            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.30624) {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.27725) {
                                    (*cnt)++;
                                    return 1;
                                } else {
                                    (*cnt)++;
                                    return 2;
                                }
                            } else {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.34545) {
                                    (*cnt)++;
                                    return 3;
                                } else {
                                    (*cnt)++;
                                    return 4;
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.91844) {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.82183) {
                                (*cnt)++;
                                return 5;
                            } else {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 0.954) {
                                    (*cnt)++;
                                    return 6;
                                } else {
                                    (*cnt)++;
                                    return 7;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.0961) {
                                (*cnt)++;
                                return 8;
                            } else {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.20395) {
                                    (*cnt)++;
                                    return 9;
                                } else {
                                    (*cnt)++;
                                    return 10;
                                }
                            }
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.78426) {
                        (*cnt)++;
                        if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.975) {
                            (*cnt)++;
                            if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 51307.26066) {
                                (*cnt)++;
                                return 11;
                            } else {
                                (*cnt)++;
                                return 12;
                            }
                        } else {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.39006) {
                                (*cnt)++;
                                return 13;
                            } else {
                                (*cnt)++;
                                return 14;
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.91496) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.235) {
                                (*cnt)++;
                                return 15;
                            } else {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.81105) {
                                    (*cnt)++;
                                    return 16;
                                } else {
                                    (*cnt)++;
                                    return 17;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.205) {
                                (*cnt)++;
                                return 18;
                            } else {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.02006) {
                                    (*cnt)++;
                                    return 19;
                                } else {
                                    (*cnt)++;
                                    return 20;
                                }
                            }
                        }
                    }
                }
            } else {
                (*cnt)++;
                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.23507) {
                    (*cnt)++;
                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.43503) {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.91043) {
                            (*cnt)++;
                            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.43) {
                                (*cnt)++;
                                return 21;
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.7205) {
                                    (*cnt)++;
                                    return 22;
                                } else {
                                    (*cnt)++;
                                    return 23;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.118) {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.08498) {
                                    (*cnt)++;
                                    return 24;
                                } else {
                                    (*cnt)++;
                                    return 25;
                                }
                            } else {
                                (*cnt)++;
                                if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 380787.40796) {
                                    (*cnt)++;
                                    return 26;
                                } else {
                                    (*cnt)++;
                                    return 27;
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.30343) {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.01826) {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.83197) {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.605) {
                                        (*cnt)++;
                                        if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.26972) {
                                            (*cnt)++;
                                            return 28;
                                        } else {
                                            (*cnt)++;
                                            return 29;
                                        }
                                    } else {
                                        (*cnt)++;
                                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.28) {
                                            (*cnt)++;
                                            return 30;
                                        } else {
                                            (*cnt)++;
                                            return 31;
                                        }
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.92402) {
                                        (*cnt)++;
                                        return 32;
                                    } else {
                                        (*cnt)++;
                                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.9425) {
                                            (*cnt)++;
                                            return 33;
                                        } else {
                                            (*cnt)++;
                                            return 34;
                                        }
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.16391) {
                                    (*cnt)++;
                                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.06351) {
                                        (*cnt)++;
                                        return 35;
                                    } else {
                                        (*cnt)++;
                                        return 36;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 37;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.075) {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.25751) {
                                    (*cnt)++;
                                    return 38;
                                } else {
                                    (*cnt)++;
                                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.76502) {
                                        (*cnt)++;
                                        if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 51068.88558) {
                                            (*cnt)++;
                                            return 39;
                                        } else {
                                            (*cnt)++;
                                            return 40;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 41;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.52495) {
                                    (*cnt)++;
                                    return 42;
                                } else {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.51415) {
                                        (*cnt)++;
                                        return 43;
                                    } else {
                                        (*cnt)++;
                                        return 44;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 8.03785) {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.99439) {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.62466) {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.9565) {
                                    (*cnt)++;
                                    return 45;
                                } else {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.2385) {
                                        (*cnt)++;
                                        return 46;
                                    } else {
                                        (*cnt)++;
                                        return 47;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.0615) {
                                    (*cnt)++;
                                    return 48;
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7.07678) {
                                        (*cnt)++;
                                        return 49;
                                    } else {
                                        (*cnt)++;
                                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.755) {
                                            (*cnt)++;
                                            return 50;
                                        } else {
                                            (*cnt)++;
                                            return 51;
                                        }
                                    }
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7.26005) {
                                (*cnt)++;
                                return 52;
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7.30995) {
                                    (*cnt)++;
                                    return 53;
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7.15) {
                                        (*cnt)++;
                                        return 54;
                                    } else {
                                        (*cnt)++;
                                        return 55;
                                    }
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 8.8217) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7.28575) {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 8.475) {
                                    (*cnt)++;
                                    return 56;
                                } else {
                                    (*cnt)++;
                                    return 57;
                                }
                            } else {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 8.67) {
                                    (*cnt)++;
                                    return 58;
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 9.4949) {
                                        (*cnt)++;
                                        return 59;
                                    } else {
                                        (*cnt)++;
                                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 8.11541) {
                                            (*cnt)++;
                                            return 60;
                                        } else {
                                            (*cnt)++;
                                            return 61;
                                        }
                                    }
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.14795) {
                                (*cnt)++;
                                return 62;
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 9.28514) {
                                    (*cnt)++;
                                    return 63;
                                } else {
                                    (*cnt)++;
                                    return 64;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            (*cnt)++;
            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 25.21582) {
                (*cnt)++;
                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14.46979) {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.27182) {
                        (*cnt)++;
                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.37225) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.22774) {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.46501) {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 9.875) {
                                        (*cnt)++;
                                        return 65;
                                    } else {
                                        (*cnt)++;
                                        return 66;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.675) {
                                        (*cnt)++;
                                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 9.7) {
                                            (*cnt)++;
                                            return 67;
                                        } else {
                                            (*cnt)++;
                                            return 68;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 69;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.80756) {
                                    (*cnt)++;
                                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.72399) {
                                        (*cnt)++;
                                        return 70;
                                    } else {
                                        (*cnt)++;
                                        return 71;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.13789) {
                                        (*cnt)++;
                                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.8045) {
                                            (*cnt)++;
                                            return 72;
                                        } else {
                                            (*cnt)++;
                                            return 73;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 74;
                                    }
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.39626) {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.79) {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 10.53221) {
                                        (*cnt)++;
                                        return 75;
                                    } else {
                                        (*cnt)++;
                                        return 76;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 77;
                                }
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.85546) {
                                    (*cnt)++;
                                    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.81899) {
                                        (*cnt)++;
                                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.5385) {
                                            (*cnt)++;
                                            return 78;
                                        } else {
                                            (*cnt)++;
                                            return 79;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 80;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.08003) {
                                        (*cnt)++;
                                        return 81;
                                    } else {
                                        (*cnt)++;
                                        return 82;
                                    }
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 13.33104) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.14503) {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.19516) {
                                    (*cnt)++;
                                    return 83;
                                } else {
                                    (*cnt)++;
                                    return 84;
                                }
                            } else {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.764) {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.5995) {
                                        (*cnt)++;
                                        return 85;
                                    } else {
                                        (*cnt)++;
                                        return 86;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 87;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 13.75638) {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 13.26011) {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.78921) {
                                        (*cnt)++;
                                        return 88;
                                    } else {
                                        (*cnt)++;
                                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 13.8256) {
                                            (*cnt)++;
                                            return 89;
                                        } else {
                                            (*cnt)++;
                                            return 90;
                                        }
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 13.74245) {
                                        (*cnt)++;
                                        return 91;
                                    } else {
                                        (*cnt)++;
                                        return 92;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 11.8576) {
                                    (*cnt)++;
                                    return 93;
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14.329) {
                                        (*cnt)++;
                                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14.14) {
                                            (*cnt)++;
                                            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14.30701) {
                                                (*cnt)++;
                                                return 94;
                                            } else {
                                                (*cnt)++;
                                                return 95;
                                            }
                                        } else {
                                            (*cnt)++;
                                            return 96;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 97;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.085) {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 15.56005) {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.65351) {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 15.09024) {
                                    (*cnt)++;
                                    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 14.31502) {
                                        (*cnt)++;
                                        return 98;
                                    } else {
                                        (*cnt)++;
                                        return 99;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 15.845) {
                                        (*cnt)++;
                                        return 100;
                                    } else {
                                        (*cnt)++;
                                        return 101;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                return 102;
                            }
                        } else {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.94) {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.10561) {
                                    (*cnt)++;
                                    if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 495088.88521) {
                                        (*cnt)++;
                                        return 103;
                                    } else {
                                        (*cnt)++;
                                        return 104;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.15577) {
                                        (*cnt)++;
                                        return 105;
                                    } else {
                                        (*cnt)++;
                                        return 106;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.21) {
                                    (*cnt)++;
                                    return 107;
                                } else {
                                    (*cnt)++;
                                    return 108;
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.38501) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.28451) {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.63546) {
                                    (*cnt)++;
                                    return 109;
                                } else {
                                    (*cnt)++;
                                    return 110;
                                }
                            } else {
                                (*cnt)++;
                                return 111;       
                            }
                        } else {
                            (*cnt)++;
                            return 112;
                        }
                    }
                }
            } else {
                (*cnt)++;
                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 38.67313) {
                    (*cnt)++;
                    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 29.1683) {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 25.99218) {
                            (*cnt)++;
                            return 113;
                        } else {
                            (*cnt)++;
                            return 114;
                        }
                    } else {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 30.84605) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 29.61001) {
                                (*cnt)++;
                                return 115;
                            } else {
                                (*cnt)++;
                                return 116;
                            }
                        } else {
                            (*cnt)++;
                            return 117;
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 45.14497) {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 36.4) {
                            (*cnt)++;
                            return 118;
                        } else {
                            (*cnt)++;
                            return 119;
                        }
                    } else {
                        (*cnt)++;
                        return 120;
                    }
                }
            }
        }
    } else {
        (*cnt)++;
        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 119.54855) {
            (*cnt)++;
            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 83.72345) {
                (*cnt)++;
                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 87.0) {
                    (*cnt)++;
                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 60.201) {
                        (*cnt)++;
                        return 121;
                    } else {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 72.55) {
                            (*cnt)++;
                            return 122;
                        } else {
                            (*cnt)++;
                            return 123;
                        }
                    }
                } else {
                    (*cnt)++;
                    return 124;
                }
            } else {
                (*cnt)++;
                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 102.47827) {
                    (*cnt)++;
                    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 95.585) {
                        (*cnt)++;
                        if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 92.59501) {
                            (*cnt)++;
                            return 125;
                        } else {
                            (*cnt)++;
                            return 126;
                        }
                    } else {
                        (*cnt)++;
                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 109.485) {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 102.02) {
                                (*cnt)++;
                                return 127;
                            } else {
                                (*cnt)++;
                                return 128;
                            }
                        } else {
                            (*cnt)++;
                            return 129;
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 116.6085) {
                        (*cnt)++;
                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 113.45236) {
                            (*cnt)++;
                            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 108.6) {
                                (*cnt)++;
                                return 130;
                            } else {
                                (*cnt)++;
                                return 131;
                            }
                        } else {
                            (*cnt)++;
                            return 132;
                        }
                    } else {
                        (*cnt)++;
                        if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 121.15001) {
                            (*cnt)++;
                            return 133;
                        } else {
                            (*cnt)++;
                            if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 124.25777) {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 118.09) {
                                    (*cnt)++;
                                    return 134;
                                } else {
                                    (*cnt)++;
                                    return 135;
                                }
                            } else {
                                (*cnt)++;
                                return 136;
                            }
                        }
                    }
                }
            }
        } else {
            (*cnt)++;
            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 163.65051) {
                (*cnt)++;
                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 142.01679) {
                    (*cnt)++;
                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 127.70005) {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 123.05051) {
                            (*cnt)++;
                            return 137;
                        } else {
                            (*cnt)++;
                            return 138;
                        }
                    } else {
                        (*cnt)++;
                        if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 139.61179) {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 135.735) {
                                (*cnt)++;
                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 131.51499) {
                                    (*cnt)++;
                                    return 139;
                                } else {
                                    (*cnt)++;
                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 127.05) {
                                        (*cnt)++;
                                        return 140;
                                    } else {
                                        (*cnt)++;
                                        return 141;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                return 142;
                            }
                        } else {
                            (*cnt)++;
                            return 143;
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 163.45) {
                        (*cnt)++;
                        return 144;
                    } else {
                        (*cnt)++;
                        return 145;
                    }
                }
            } else {
                (*cnt)++;
                return 146;
            }
        }
    }
    
}

// energy
int tree5(float features[], int *cnt, int node_loc, int flag, int ifFIA)
{
    float fia_force = (flag == 1) ? FLT_MAX : -FLT_MAX;
    if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.0) {
        (*cnt)++;
        if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 72.4609) {
            (*cnt)++;
            if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 23.31425) {
                (*cnt)++;
                if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 27.32351) {
                    (*cnt)++;
                    if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.49514) {
                        (*cnt)++;
                        if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 23.91167) {
                            (*cnt)++;
                            return 0;
                        } else {
                            (*cnt)++;
                            return 1;
                        }
                    } else {
                        (*cnt)++;
                        if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 30.16867) {
                            (*cnt)++;
                            if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.11667) {
                                (*cnt)++;
                                return 2;
                            } else {
                                (*cnt)++;
                                return 3;
                            }
                        } else {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 36.29108) {
                                (*cnt)++;
                                return 4;
                            } else {
                                (*cnt)++;
                                if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 765.375) {
                                    (*cnt)++;
                                    return 5;
                                } else {
                                    (*cnt)++;
                                    return 6;
                                }
                            }
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 751.67752) {
                        (*cnt)++;
                        if (features[22] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 1.52778) {
                            (*cnt)++;
                            if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 58.33333) {
                                (*cnt)++;
                                return 7;
                            } else {
                                (*cnt)++;
                                return 8;
                            }
                        } else {
                            (*cnt)++;
                            if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 81.52903) {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 48.58833) {
                                    (*cnt)++;
                                    if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 35.17048) {
                                        (*cnt)++;
                                        return 9;
                                    } else {
                                        (*cnt)++;
                                        return 10;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 11;
                                }
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.53333) {
                                    (*cnt)++;
                                    return 12;
                                } else {
                                    (*cnt)++;
                                    return 13;
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[17] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.63925) {
                            (*cnt)++;
                            return 14;
                        } else {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.33778) {
                                (*cnt)++;
                                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34.86667) {
                                    (*cnt)++;
                                    return 15;
                                } else {
                                    (*cnt)++;
                                    return 16;
                                }
                            } else {
                                (*cnt)++;
                                if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 38.56943) {
                                    (*cnt)++;
                                    if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 32.28104) {
                                        (*cnt)++;
                                        return 17;
                                    } else {
                                        (*cnt)++;
                                        if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.19588) {
                                            (*cnt)++;
                                            if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 32.10833) {
                                                (*cnt)++;
                                                return 18;
                                            } else {
                                                (*cnt)++;
                                                return 19;
                                            }
                                        } else {
                                            (*cnt)++;
                                            if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 23.45171) {
                                                (*cnt)++;
                                                return 20;
                                            } else {
                                                (*cnt)++;
                                                if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34.741) {
                                                    (*cnt)++;
                                                    return 21;
                                                } else {
                                                    (*cnt)++;
                                                    return 22;
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[23] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.08437) {
                                        (*cnt)++;
                                        return 23;
                                    } else {
                                        (*cnt)++;
                                        return 24;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                (*cnt)++;
                if (features[7] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.11077) {
                    (*cnt)++;
                    if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24.25428) {
                        (*cnt)++;
                        if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 44.39417) {
                            (*cnt)++;
                            if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.86146) {
                                (*cnt)++;
                                if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 40.92833) {
                                    (*cnt)++;
                                    return 25;
                                } else {
                                    (*cnt)++;
                                    return 26;
                                }
                            } else {
                                (*cnt)++;
                                return 27;
                            }
                        } else {
                            (*cnt)++;
                            if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 44.86333) {
                                (*cnt)++;
                                return 28;
                            } else {
                                (*cnt)++;
                                return 29;
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 59.83333) {
                            (*cnt)++;
                            return 30;
                        } else {
                            (*cnt)++;
                            if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 25.375) {
                                (*cnt)++;
                                return 31;
                            } else {
                                (*cnt)++;
                                return 32;
                            }
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 26.83558) {
                        (*cnt)++;
                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 48.00461) {
                            (*cnt)++;
                            if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34.24519) {
                                (*cnt)++;
                                if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.54416) {
                                    (*cnt)++;
                                    if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 38.31667) {
                                        (*cnt)++;
                                        return 33;
                                    } else {
                                        (*cnt)++;
                                        return 34;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.30599) {
                                        (*cnt)++;
                                        return 35;
                                    } else {
                                        (*cnt)++;
                                        if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 38.96344) { 
                                            (*cnt)++;
                                            if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.10188) {
                                                (*cnt)++;
                                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24.13498) {
                                                    (*cnt)++;
                                                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 28.49979) {
                                                        (*cnt)++;
                                                        return 36;
                                                    } else {
                                                        (*cnt)++;
                                                        if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 37.19604) {
                                                            (*cnt)++;
                                                            if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 32.86951) {
                                                                (*cnt)++;
                                                                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24.98167) {
                                                                    (*cnt)++;
                                                                    if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 39.36333) {
                                                                        (*cnt)++;
                                                                        return 37;
                                                                    } else {
                                                                        (*cnt)++;
                                                                        return 38;
                                                                    }
                                                                } else {
                                                                    (*cnt)++;
                                                                    return 39;
                                                                }
                                                            } else {
                                                                (*cnt)++;
                                                                return 40;
                                                            }
                                                        } else {
                                                            (*cnt)++;
                                                            return 41;
                                                        }
                                                    }
                                                } else {
                                                    (*cnt)++;
                                                    return 42;
                                                }
                                            } else {
                                                (*cnt)++;
                                                return 43;
                                            }
                                        } else {
                                            (*cnt)++;
                                            return 44;
                                        }
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 46.936) {
                                    (*cnt)++;
                                    if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.70679) {
                                        (*cnt)++;
                                        return 45;
                                    } else {
                                        (*cnt)++;
                                        return 46;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 46.43155) {
                                        (*cnt)++;
                                        if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.32833) {
                                            (*cnt)++;
                                            return 47;
                                        } else {
                                            (*cnt)++;
                                            return 48;
                                        }
                                    } else {
                                        (*cnt)++;
                                        if (features[22] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 6.58333) {
                                            (*cnt)++;
                                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 35.61115) {
                                                (*cnt)++;
                                                return 49;
                                            } else {
                                                (*cnt)++;
                                                if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 48.14722) {
                                                    (*cnt)++;
                                                    return 50;
                                                } else {
                                                    (*cnt)++;
                                                    return 51;
                                                }
                                            }
                                        } else {
                                            (*cnt)++;
                                            if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 68.25) {
                                                (*cnt)++;
                                                return 52;
                                            } else {
                                                (*cnt)++;
                                                return 53;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.96699) {
                                (*cnt)++;
                                if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.91604) {
                                    (*cnt)++;
                                    return 54;
                                } else {
                                    (*cnt)++;
                                    return 55;
                                }
                            } else {
                                (*cnt)++;
                                return 56;
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 40.79201) {
                            (*cnt)++;
                            if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 4.46) {
                                (*cnt)++;
                                return 57;
                            } else {
                                (*cnt)++;
                                return 58;
                            }
                        } else {
                            (*cnt)++;
                            return 59;
                        }
                    }
                }
            }
        } else {
            (*cnt)++;
            if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 39.08647) {
                (*cnt)++;
                if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 20.51301) {
                    (*cnt)++;
                    if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 37.60699) {
                        (*cnt)++;
                        if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.405) {
                            (*cnt)++;
                            return 60;
                        } else {
                            (*cnt)++;
                            if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34.99833) {
                                (*cnt)++;
                                return 61;
                            } else {
                                (*cnt)++;
                                if (features[7] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.13333) {
                                    (*cnt)++;
                                    return 62;
                                } else {
                                    (*cnt)++;
                                    return 63;
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        return 64;
                    }
                } else {
                    (*cnt)++;
                    if (features[7] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.7297) {
                        (*cnt)++;
                        if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.42667) {
                            (*cnt)++;
                            return 65;
                        } else {
                            (*cnt)++;
                            return 66;
                        }
                    } else {
                        (*cnt)++;
                        if (features[19] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.41365) {
                            (*cnt)++;
                            return 67;
                        } else {
                            (*cnt)++;
                            if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.04884) {
                                (*cnt)++;
                                return 68;
                            } else {
                                (*cnt)++;
                                if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.43865) {
                                    (*cnt)++;
                                    return 69;
                                } else {
                                    (*cnt)++;
                                    return 70;
                                }
                            }
                        }
                    }
                }
            } else {
                (*cnt)++;
                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.55543) {
                    (*cnt)++;
                    if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 80.88372) {
                        (*cnt)++;
                        if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 42.88448) {
                            (*cnt)++;
                            if (features[23] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.83756) {
                                (*cnt)++;
                                if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 20.58312) {
                                    (*cnt)++;
                                    if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.2969) {
                                        (*cnt)++;
                                        if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 768.38333) {
                                            (*cnt)++;
                                            return 71;
                                        } else {
                                            (*cnt)++;
                                            return 72;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 73;
                                    }
                                } else {
                                    (*cnt)++;
                                    if (features[11] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.92209) {
                                        (*cnt)++;
                                        return 74;
                                    } else {
                                        (*cnt)++;
                                        if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.395) {
                                            (*cnt)++;
                                            return 75;
                                        } else {
                                            (*cnt)++;
                                            return 76;
                                        }
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 62.02667) {
                                    (*cnt)++;
                                    return 77;
                                } else {
                                    (*cnt)++;
                                    return 78;
                                }
                            }
                        } else {
                            (*cnt)++;
                            return 79;
                        }
                    } else {
                        (*cnt)++;
                        if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 42.475) {
                            (*cnt)++;
                            return 80;
                        } else {
                            (*cnt)++;
                            return 81;
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 52.61841) {
                        (*cnt)++;
                        if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 48.35192) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.7347) {
                                (*cnt)++;
                                if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.15817) {
                                    (*cnt)++;
                                    return 82;
                                } else {
                                    (*cnt)++;
                                    if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.57826) {
                                        (*cnt)++;
                                        if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.64872) {
                                            (*cnt)++;
                                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 20.32333) {
                                                (*cnt)++;
                                                return 83;
                                            } else {
                                                (*cnt)++;
                                                return 84;
                                            }
                                        } else {
                                            (*cnt)++;
                                            return 85;
                                        }
                                    } else {
                                        (*cnt)++;
                                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 41.99098) {
                                            (*cnt)++;
                                            return 86;
                                        } else {
                                            (*cnt)++;
                                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.57995) {
                                                (*cnt)++;
                                                if (features[11] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 3.821) {
                                                    (*cnt)++;
                                                    return 87;
                                                } else {
                                                    (*cnt)++;
                                                    return 88;
                                                }
                                            } else {
                                                (*cnt)++;
                                                return 89;
                                            }
                                        }
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24.12892) {
                                    (*cnt)++;
                                    if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24.61771) {
                                        (*cnt)++;
                                        if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34.2898) {
                                            (*cnt)++;
                                            if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.48333) {
                                                (*cnt)++;
                                                return 90;
                                            } else {
                                                (*cnt)++;
                                                return 91;
                                            }
                                        } else {
                                            (*cnt)++;
                                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 47.76613) {
                                                (*cnt)++;
                                                return 92;
                                            } else {
                                                (*cnt)++;
                                                return 93;
                                            }
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 94;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 95;
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 735.625) {
                                (*cnt)++;
                                if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 49.95528) {
                                    (*cnt)++;
                                    return 96;
                                } else {
                                    (*cnt)++;
                                    return 97;
                                }
                            } else {
                                (*cnt)++;
                                if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 12.68603) {
                                    (*cnt)++;
                                    return 98;
                                } else {
                                    (*cnt)++;
                                    if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 48.01315) {
                                        (*cnt)++;
                                        return 99;
                                    } else {
                                        (*cnt)++;
                                        return 100;
                                    }
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 54.64455) {
                            (*cnt)++;
                            return 101;
                        } else {
                            (*cnt)++;
                            return 102;
                        }
                    }
                }
            }
        }
    } else {
        (*cnt)++;
        if (features[17] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.13787) {
            (*cnt)++;
            if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 37.10643) {
                (*cnt)++;
                return 103;
            } else {
                (*cnt)++;
                if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 39.98588) {
                    (*cnt)++;
                    return 104;
                } else {
                    (*cnt)++;
                    if (features[19] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 2.40671) {
                        (*cnt)++;
                        return 105;
                    } else {
                        (*cnt)++;
                        if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 15.0) {
                            (*cnt)++;
                            if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 38.74295) {
                                (*cnt)++;
                                return 106;
                            } else {
                                (*cnt)++;
                                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 71.74843) {
                                    (*cnt)++;
                                    return 107;
                                } else {
                                    (*cnt)++;
                                    if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 16.80944) {
                                        (*cnt)++;
                                        return 108;
                                    } else {
                                        (*cnt)++;
                                        return 109;
                                    }
                                }
                            }
                        } else {
                            (*cnt)++;
                            if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.0521) {
                                (*cnt)++;
                                if (features[22] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.08333) {
                                    (*cnt)++;
                                    return 110;
                                } else {
                                    (*cnt)++;
                                    if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.96333) {
                                        (*cnt)++;
                                        if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.73) {
                                            (*cnt)++;
                                            return 111;
                                        } else {
                                            (*cnt)++;
                                            return 112;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 113;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                return 114;
                            }
                        }
                    }
                }
            }
        } else {
            (*cnt)++;
            if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 80.69733) {
                (*cnt)++;
                if (features[22] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 5.76944) {
                    (*cnt)++;
                    if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 58.42884) {
                        (*cnt)++;
                        if (features[5] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 23.07751) {
                            (*cnt)++;
                            if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.725) {
                                (*cnt)++;
                                if (features[10] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 44.61717) {
                                    (*cnt)++;
                                    if (features[18] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 40.13278) {
                                        (*cnt)++;
                                        return 115;
                                    } else {
                                        (*cnt)++;
                                        if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.62083) {
                                            (*cnt)++;
                                            return 116;
                                        } else {
                                            (*cnt)++;
                                            return 117;
                                        }
                                    }
                                } else {
                                    (*cnt)++;
                                    return 118;
                                }
                            } else {
                                (*cnt)++;
                                return 119;
                            }
                        } else {
                            (*cnt)++;
                            if (features[1] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 22.47156) {
                                (*cnt)++;
                                if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.32333) {
                                    (*cnt)++;
                                    return 120;
                                } else {
                                    (*cnt)++;
                                    if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 20.715) {
                                        (*cnt)++;
                                        if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.525) {
                                            (*cnt)++;
                                            if (features[24] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 48.27453) {
                                                (*cnt)++;
                                                return 121;
                                            } else {
                                                (*cnt)++;
                                                return 122;
                                            }
                                        } else {
                                            (*cnt)++;
                                            return 123;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 124;
                                    }
                                }
                            } else {
                                (*cnt)++;
                                if (features[3] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 20.54313) {
                                    (*cnt)++;
                                    return 125;
                                } else {
                                    (*cnt)++;
                                    if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 7.80361) {
                                        (*cnt)++;
                                        return 126;
                                    } else {
                                        (*cnt)++;
                                        if (features[21] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 57.70833) {
                                            (*cnt)++;
                                            return 127;
                                        } else {
                                            (*cnt)++;
                                            return 128;
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[17] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.08333) {
                            (*cnt)++;
                            if (features[9] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 17.57464) {
                                (*cnt)++;
                                if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 28.99667) {
                                    (*cnt)++;
                                    if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 36.33) {
                                        (*cnt)++;
                                        return 129;
                                    } else {
                                        (*cnt)++;
                                        return 130;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 131;
                                }
                            } else {
                                (*cnt)++;
                                return 132;
                            }
                        } else {
                            (*cnt)++;
                            return 133;
                        }
                    }
                } else {
                    (*cnt)++;
                    if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 757.75678) {
                        (*cnt)++;
                        if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 741.88542) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 43.37167) {
                                (*cnt)++;
                                if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.45111) {
                                    (*cnt)++;
                                    if (features[6] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 42.6) {
                                        (*cnt)++;
                                        return 134;
                                    } else {
                                        (*cnt)++;
                                        return 135;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 136;
                                }
                            } else {
                                (*cnt)++;
                                return 137;
                            }
                        } else {
                            (*cnt)++;
                            if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 21.76188) {
                                (*cnt)++;
                                if (features[20] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 757.51667) {
                                    (*cnt)++;
                                    if (features[15] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 18.96222) {
                                        (*cnt)++;
                                        if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 44.43333) {
                                            (*cnt)++;
                                            return 138;
                                        } else {
                                            (*cnt)++;
                                            return 139;
                                        }
                                    } else {
                                        (*cnt)++;
                                        return 140;
                                    }
                                } else {
                                    (*cnt)++;
                                    return 141;
                                }
                            } else {
                                (*cnt)++;
                                return 142;
                            }
                        }
                    } else {
                        (*cnt)++;
                        if (features[14] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 24.71982) {
                            (*cnt)++;
                            if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 34.36167) {
                                (*cnt)++;
                                if (features[0] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 15.0) {
                                    (*cnt)++;
                                    return 143;
                                } else {
                                    (*cnt)++;
                                    return 144;
                                }
                            } else {
                                (*cnt)++;
                                return 145;
                            }
                        } else {
                            (*cnt)++;
                            if (features[13] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 19.05143) {
                                (*cnt)++;
                                if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 51.27514) {
                                    (*cnt)++;
                                    if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 72.49667) {
                                        (*cnt)++;
                                        return 146;
                                    } else {
                                        (*cnt)++;
                                        if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 85.49667) {
                                            (*cnt)++;
                                            return 147;
                                        } else {
                                            (*cnt)++;
                                            return 148;
                                        }
                                    }
                                } else {
                                    (*cnt)++;
                                    return 149;
                                }
                            } else {
                                (*cnt)++;
                                return 150;
                            }
                        }
                    }
                }
            } else {
                (*cnt)++;
                if (features[8] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 38.55699) {
                    (*cnt)++;
                    if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 93.01071) {
                        (*cnt)++;
                        return 151;
                    } else {
                        (*cnt)++;
                        return 152;
                    }
                } else {
                    (*cnt)++;
                    if (features[4] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 40.23726) {
                        (*cnt)++;
                        if (features[12] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 90.34597) {
                            (*cnt)++;
                            return 153;
                        } else {
                            (*cnt)++;
                            return 154;
                        }
                    } else {
                        (*cnt)++;
                        if (features[16] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 51.619) {
                            (*cnt)++;
                            if (features[2] + (((*cnt == node_loc) && (ifFIA == 1)) ? fia_force : 0.0) < 45.2778) {
                                (*cnt)++;
                                return 155;
                            } else {
                                (*cnt)++;
                                return 156;
                            }
                        } else {
                            (*cnt)++;
                            return 157;
                        }
                    }
                }
            }
        }
    }
}

// Define the global tree function pointer
TreeFunction tree = NULL;

// Function to set the tree function globally
void set_tree_function(TreeType type) {
    switch (type) {
        case TREE_TYPE_1:
            tree = tree1;
            break;
        case TREE_TYPE_2:
            tree = tree2;
            break;
        case TREE_TYPE_3:
            tree = tree3;
            break;
        case TREE_TYPE_4:
            tree = tree4;
            break;
        case TREE_TYPE_5:
            tree = tree5;
            break;
        default:
            printf("Error: Invalid tree type!\n");
            tree = NULL;
    }
}
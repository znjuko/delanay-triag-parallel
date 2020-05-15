//
// Created by znjuko on 15.05.2020.
//


float Solve33(const std::vector<std::vector<float>>& matrix33) {
    float firstSquare = matrix33[0][0] * (matrix33[1][1] * matrix33[2][2] - matrix33[1][2] * matrix33[2][1]);
    float secondSquare = matrix33[0][1] * (matrix33[1][0] * matrix33[2][2] - matrix33[1][2] * matrix33[2][0]);
    float thirdSquare = matrix33[0][2] * (matrix33[1][0] * matrix33[2][1] - matrix33[1][1] * matrix33[2][0]);
    return firstSquare - secondSquare + thirdSquare;
};

float Solve44(const std::vector<std::vector<float>>& matrix44) {


    std::vector<std::vector<float>> array1(3);
    for (unsigned int i = 1; i < 4; i++) {
        array1[i - 1].push_back(matrix44[i][1]);
        array1[i - 1].push_back(matrix44[i][2]);
        array1[i - 1].push_back(matrix44[i][3]);
    }
    float firstSquare = matrix44[0][0] * Solve33(array1);

    std::vector<std::vector<float>> array2(3);
    for (unsigned int i = 1; i < 4; i++) {
        array2[i - 1].push_back(matrix44[i][0]);
        array2[i - 1].push_back(matrix44[i][2]);
        array2[i - 1].push_back(matrix44[i][3]);
    }
    float secondSquare = matrix44[0][1] * Solve33(array2);


    std::vector<std::vector<float>> array3(3);
    for (unsigned int i = 1; i < 4; i++) {
        array3[i - 1].push_back(matrix44[i][0]);
        array3[i - 1].push_back(matrix44[i][1]);
        array3[i - 1].push_back(matrix44[i][3]);
    }
    float thirdSquare = matrix44[0][2] * Solve33(array3);


    std::vector<std::vector<float>> array4(3);
    for (unsigned int i = 1; i < 4; i++) {
        array4[i - 1].push_back(matrix44[i][0]);
        array4[i - 1].push_back(matrix44[i][1]);
        array4[i - 1].push_back(matrix44[i][2]);
    }
    float fourthSquare = matrix44[0][3] * Solve33(array4);

    return firstSquare - secondSquare + thirdSquare - fourthSquare;
}


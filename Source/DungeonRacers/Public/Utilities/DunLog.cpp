#include "DunLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameProject, Display, All)

DunLog::DunLog()
{
}

DunLog::~DunLog()
{
}

void DunLog::Print(int32 InValue, int32 InKey, float Duration, FColor InColor)
{
    GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::FromInt(InValue));

}

void DunLog::Print(float InValue, int32 InKey, float Duration, FColor InColor)
{
    GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::SanitizeFloat(InValue));//float�� string����
}

void DunLog::Print(const FString& InValue, int32 InKey, float Duration, FColor InColor)
{
    GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue);
}

void DunLog::Print(const FVector& InValue, int32 InKey, float Duration, FColor InColor)
{
    GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());

}

void DunLog::Print(const FRotator& InValue, int32 InKey, float Duration, FColor InColor)
{
    GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());

}

void DunLog::Log(int32 InValue)
{
    //UE_LOG(LogTemp, Display, L"%d", InValue);
    UE_LOG(GameProject, Display, L"%d", InValue);
}

void DunLog::Log(float InValue)
{
    UE_LOG(GameProject, Display, L"%f", InValue);

}

void DunLog::Log(const FString& InValue)
{
    UE_LOG(GameProject, Display, L"%s", *InValue);

}

void DunLog::Log(const FVector& InValue)
{
    UE_LOG(GameProject, Display, L"%s", *InValue.ToString());

}

void DunLog::Log(const FRotator& InValue)
{
    UE_LOG(GameProject, Display, L"%s", *InValue.ToString());

}

void DunLog::Log(const UObject* InObject)
{
    FString str;
    if (!!InObject)
        str.Append(InObject->GetName());
    str.Append(!!InObject ? " Not Null" : " Null");

    UE_LOG(GameProject, Display, L"%s", *str);
}

void DunLog::Log(const FString& InFuncName, int32 InLineNumber)
{
    FString str;
    str.Append(InFuncName);
    str.Append(", ");
    str.Append(FString::FromInt(InLineNumber));

    UE_LOG(GameProject, Display, L"%s", *str);
}